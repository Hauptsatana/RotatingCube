#include "render_area.h"
#include <QPainter>

#include "matrix_util.h"
#include "guides3d.h"
#include "cube.h"

RenderArea::RenderArea(QWidget* parent) : QFrame(parent) {
	//setBackgroundRole(QPalette::Base);
	//setAutoFillBackground(true);
	
	h_mproj = *MatrixUtil::h_projectionIsometric();

	frames = std::vector<Frame3D*>();
	frames.push_back(new Cube());
}

void RenderArea::addFrame(Frame3D* frame) {
	frames.push_back(frame);
}

void RenderArea::setProjection(Projection proj) {
	switch (proj) {
		case Isometric: 
			h_mproj = *MatrixUtil::h_projectionIsometric(); 
			break;
		case Dimetric:
			h_mproj = *MatrixUtil::h_projectionDimetric();
			break;
		case Cabinet:
			h_mproj = *MatrixUtil::h_projectionCabinet();
			break;
	}
}

// Проекцирование остова на плоскость - проекция всех точек и нахождение их границ
ProcessedFrame* RenderArea::processFrame(const Frame3D& frame, Matrix<double, 4, 4>& h_mproj) {
	double xmin = std::numeric_limits<double>::max();
	double xmax = std::numeric_limits<double>::min();
	double ymin = std::numeric_limits<double>::max();
	double ymax = std::numeric_limits<double>::min();

	int pcount = frame.getPointsCount();
	Point2D** pp = new Point2D*[pcount];
	for (int i = 0; i < pcount; i++) {
		// Проецирование на плоскость с проверкой z-координаты на 0
		Point3D* pproj = frame.getPoint(i)->h_transform(h_mproj);
		assert(abs(pproj->getZ()) < 0.001);
		pp[i] = pproj->getPoint2D();
		delete pproj;
		// Расчет границ
		xmin = std::min(xmin, pp[i]->getX());
		xmax = std::max(xmax, pp[i]->getX());
		ymin = std::min(ymin, pp[i]->getY());
		ymax = std::max(ymax, pp[i]->getY());
	}
	
	ProcessedFrame* res = new ProcessedFrame(
		xmin, xmax, ymin, ymax, pp, pcount);
	return res;
}

// Отрисовка остова
void paintFrame(const Frame3D& frame, ProcessedFrame* pf, Matrix<double, 3, 3>* h_mmap, QPainter& painter) {
	int lcount = frame.getLinksCount();
	for (int j = 0; j < lcount; j++) {
		int* links = frame.getLink(j);
		Point2D* p1 = pf->flatPoints[links[0]]->h_transform(*h_mmap);
		Point2D* p2 = pf->flatPoints[links[1]]->h_transform(*h_mmap);
		painter.drawLine(QPointF(p1->getX(), p1->getY()), QPointF(p2->getX(), p2->getY()));
	}
}

void RenderArea::paintEvent(QPaintEvent* event) {

	//
	ProcessedFrame* guidesPf = processFrame(guides, h_mproj);

	// Глобальные границы 
	double gxmin = guidesPf->xmin;
	double gxmax = guidesPf->xmax;
	double gymin = guidesPf->ymin;
	double gymax = guidesPf->ymax;

	// Обработка всех остовов
	std::vector<ProcessedFrame*> pfs;
	for (std::vector<Frame3D*>::size_type i = 0; i < frames.size(); i++) {
		ProcessedFrame* pf = processFrame(*frames[i], h_mproj);
		pfs.push_back(pf);
		gxmin = std::min(gxmin, pf->xmin);
		gxmax = std::max(gxmax, pf->xmax);
		gymin = std::min(gymin, pf->ymin);
		gymax = std::max(gymax, pf->ymax);
	}

	// Матрица отображения жекартовых координат в экранные
	Matrix<double, 3, 3>* h_mmap = MatrixUtil::cartesian2DToScreenMapping(
		gxmin, gxmax, gymin, gymax, width(), height(), equalScale);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	// Расположение проекции по центру при одинаковом масштабе по осям
	if (equalScale) {
		double dx = gxmax - gxmin;
		double dy = gymax - gymin;
		double sx = width() / dx;
		double sy = height() / dy;
		double smin = std::min(sx, sy);
		double dw = width() - smin * dx;
		double dh = height() - smin * dy;
		painter.translate(dw / 2, dh / 2);
	}

	// Отрисовка координатных осей разными цветами
	QBrush colors[3] = { Qt::darkRed, Qt::darkGreen, Qt::darkBlue };
	Point2D* pzero = guidesPf->flatPoints[0]->h_transform(*h_mmap);
	QPointF qzero = QPointF(pzero->getX(), pzero->getY());
	for (int i = 1; i < 4; i++) {
		Point2D* p = guidesPf->flatPoints[i]->h_transform(*h_mmap);
		painter.setPen(QPen(colors[i - 1], 2, Qt::DashLine, Qt::FlatCap));
		painter.drawLine(qzero, QPoint(p->getX(), p->getY()));
	}

	// Отрисовка отрезков всех остовов
	painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
	for (std::vector<Frame3D*>::size_type i = 0; i < frames.size(); i++) {
		paintFrame(*frames[i], pfs[i], h_mmap, painter);
	}
}


// SLOTS

void RenderArea::transformAndRender() {
	
	// Повороты на указанные углы
	if (rotX && angleX != 0) {
		Matrix<double, 3, 3>* rotX = MatrixUtil::rotation3DX(angleX);
		for (int i = 0; i < frames.size(); i++) {
			frames[i]->selfTransform(*rotX);
		}
	}
	if (rotY && angleY != 0) {
		Matrix<double, 3, 3>* rotY = MatrixUtil::rotation3DY(angleY);
		for (int i = 0; i < frames.size(); i++) {
			frames[i]->selfTransform(*rotY);
		}
	}
	if (rotZ && angleZ != 0) {
		Matrix<double, 3, 3>* rotZ = MatrixUtil::rotation3DZ(angleZ);
		for (int i = 0; i < frames.size(); i++) {
			frames[i]->selfTransform(*rotZ);
		}
	}

	update(); // Принудительная перерисовка
}

// Углы
void RenderArea::setRotX(bool rotX) {
	this->rotX = rotX;
}
void RenderArea::setRotY(bool rotY) {
	this->rotY = rotY;
}
void RenderArea::setRotZ(bool rotZ) {
	this->rotZ = rotZ;
}
void RenderArea::setAngleX(double angleX) {
	this->angleX = angleX;
}
void RenderArea::setAngleY(double angleY) {
	this->angleY = angleY;
}
void RenderArea::setAngleZ(double angleZ) {
	this->angleZ = angleZ;
}
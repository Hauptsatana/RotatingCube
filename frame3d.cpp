#include "frame3d.h"
#include <assert.h>

Frame3D::Frame3D(Point3D** points, int pcount, int* links, int lcount) {
	this->pcount = pcount;
	this->points = new Point3D*[pcount];
	for (int i = 0; i < pcount; i++) {
		this->points[i] = points[i];
	}
	this->lcount = lcount;
	this->links = new int[lcount * 2];
	for (int i = 0; i < lcount * 2; i++) {
		this->links[i]  = links[i];
	}
}

Frame3D::Frame3D(const Frame3D& frame) {
	this->pcount = frame.pcount;
	this->points = new Point3D*[pcount];
	for (int i = 0; i < pcount; i++) {
		this->points[i] = frame.points[i];
	}
	this->lcount = frame.lcount;
	this->links = new int[lcount * 2];
	for (int i = 0; i < lcount * 2; i++) {
		this->links[i] = frame.links[i];
	}
}

// Очистка ресурсов
//Frame3D::~Frame3D() {
	/*delete[] points;
	for (int i = 0; i < lcount; i++) {
		delete[] links[i];
	}
	delete[] links;*/
//}

// Безопасный доступ
int Frame3D::checkPoint(int index) const {
	assert(index >= 0 && index < pcount);
	return index;
}
int Frame3D::checkLink(int index) const {
	assert(index >= 0 && index < lcount);
	return index;
}

// Точки и отрезки
int Frame3D::getPointsCount() const {
	return pcount;
}
Point3D* Frame3D::getPoint(int index) const {
	return points[checkPoint(index)];
}

int Frame3D::getLinksCount() const {
	return lcount;
}
int* Frame3D::getLink(int index) const {
	//return links[checkLink(index)];
	int* res = new int[2];
	res[0] = links[2 * index];
	res[1] = links[2 * index + 1];
	return res;
}

// Преобразования - делегирование преобразований к каждой точке
void Frame3D::selfTransform(const Matrix<double, 3, 3>& matr) {
	for (int i = 0; i < pcount; i++) {
		points[i]->selfTransform(matr);
	}
}
void Frame3D::h_selfTransform(const Matrix<double, 4, 4>& matr) {
	for (int i = 0; i < pcount; i++) {
		points[i]->h_selfTransform(matr);
	}
}
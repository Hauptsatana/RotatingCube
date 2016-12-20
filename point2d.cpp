#include "point2d.h"

Point2D::Point2D(double x, double y) {
	data[0] = x;
	data[1] = y;
}

// Координаты
const double Point2D::getX() const {
	return data[0];
}
void Point2D::setX(double value) {
	data[0] = value;
}
const double Point2D::getY() const {
	return data[1];
}
void Point2D::setY(double value) {
	data[1] = value;
}

// Преобразование координат
Point2D* Point2D::transform(const Matrix<double, 2, 2>& matr) const {
	return new Point2D((*this) * matr);
}
void Point2D::selfTransform(const Matrix<double, 2, 2>& matr) {
	Point2D* np = transform(matr);
	this->setX(np->getX());
	this->setY(np->getY());
	delete np;
}

// Однородное преобразование
Point2D* Point2D::h_transform(const Matrix<double, 3, 3>& h_matr) const {
	VectorH<double, 3>* h_coords = this->addItem(1);
	Matrix<double, 1, 3> mult = (*h_coords) * h_matr;
	double x = mult.get(0, 0);
	double y = mult.get(0, 1);
	double h = mult.get(0, 2);
	delete h_coords;
	// !!! - h == 0
	return new Point2D(x / h, y / h);
}
void Point2D::h_selfTransform(const Matrix<double, 3, 3>& h_matr) {
	Point2D* np = h_transform(h_matr);
	this->setX(np->getX());
	this->setY(np->getY());
	delete np;
}
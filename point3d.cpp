#include "point3d.h"

Point3D::Point3D(double x, double y, double z) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

// Координаты
const double Point3D::getX() const {
	return data[0];
}
void Point3D::setX(double value) {
	data[0] = value;
}
const double Point3D::getY() const {
	return data[1];
}
void Point3D::setY(double value) {
	data[1] = value;
}
const double Point3D::getZ() const {
	return data[2];
}
void Point3D::setZ(double value) {
	data[2] = value;
}

// Преобразование координат
Point3D* Point3D::transform(const Matrix<double, 3, 3>& matr) {
	return new Point3D((*this) * matr);
}

void Point3D::selfTransform(const Matrix<double, 3, 3>& matr) {
	Point3D* np = transform(matr);
	this->setX(np->getX());
	this->setY(np->getY());
	this->setZ(np->getZ());
	delete np;
}

// Однородное преобразование
Point3D* Point3D::h_transform(const Matrix<double, 4, 4>& matr) {
	VectorH<double, 4>* h_coords = this->addItem(1);
	Matrix<double, 1, 4> mult = (*h_coords) * matr;
	double x = mult.get(0, 0);
	double y = mult.get(0, 1);
	double z = mult.get(0, 2);
	double h = mult.get(0, 3);
	delete h_coords;
	// !!! - h == 0
	return new Point3D(x / h, y / h, z / h);
}

void Point3D::h_selfTransform(const Matrix<double, 4, 4>& matr) {
	Point3D* np = h_transform(matr);
	this->setX(np->getX());
	this->setY(np->getY());
	this->setZ(np->getZ());
	delete np;
}

Point2D* Point3D::getPoint2D() {
	return new Point2D(this->getX(), this->getY());
}
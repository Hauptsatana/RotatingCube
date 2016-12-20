#pragma once
#include "point2d.h"

// Точка в трехмерном пространстве
class Point3D : private VectorH<double, 3> {

public:
	Point3D() : VectorH<double, 3>() {}
	Point3D(double x, double y, double z);
	Point3D(const Point3D& point) : VectorH<double, 3>(point) {}
	Point3D(const VectorH<double, 3>& vec) : VectorH<double, 3>(vec) {}
	Point3D(const Matrix<double, 1, 3>& matr) : VectorH<double, 3>(matr) {}

	// Координаы
	const double getX() const;
	void setX(double value);
	const double getY() const;
	void setY(double value);
	const double getZ() const;
	void setZ(double value);

	// Преобразования
	// h_ - однородные преобразования (с доп. координатой)
	Point3D* transform(const Matrix<double, 3, 3>& matr);
	void selfTransform(const Matrix<double, 3, 3>& matr);
	Point3D* h_transform(const Matrix<double, 4, 4>& matr);
	void h_selfTransform(const Matrix<double, 4, 4>& matr);

	// Проекция точки на плоскость XOY
	Point2D* getPoint2D();
};
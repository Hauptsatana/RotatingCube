#pragma once
#include "vector_h.h"

// Точка на плоскости
class Point2D : private VectorH<double, 2> {

public:
	Point2D() : VectorH<double, 2>() {}
	Point2D(double x, double y);
	Point2D(const Point2D& point) : VectorH<double, 2>(point) {}
	Point2D(const VectorH<double, 2>& vec) : VectorH<double, 2>(vec) {}
	Point2D(const Matrix<double, 1, 2>& matr) : VectorH<double, 2>(matr) {}

	// Координаты
	const double getX() const;
	void setX(double value);
	const double getY() const;
	void setY(double value);

	// Преобразования
	// h_ - однородные преобразования (с доп. координатой)
	Point2D* transform(const Matrix<double, 2, 2>& matr) const;
	void selfTransform(const Matrix<double, 2, 2>& matr);
	Point2D* h_transform(const Matrix<double, 3, 3>& h_matr) const;
	void h_selfTransform(const Matrix<double, 3, 3>& h_matr);
};
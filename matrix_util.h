#pragma once
#include "matrix.h"

class MatrixUtil 
{
public:
	// h_ - однородная матрица (добавлена координата h)

	// Матрицы отражения
	static Matrix<double, 3, 3>* h_reflection2DOX();
	static Matrix<double, 3, 3>* h_reflection2DOY();

	// Матрицы масштабирования
	static Matrix<double, 3, 3>* h_scaling2D(double sx, double sy);

	// Матрицы переноса
	static Matrix<double, 3, 3>* h_translation2D(double dx, double dy);

	// Матрицы поворота вокруг осей
	static Matrix<double, 3, 3>* rotation3DX(double degrees);
	static Matrix<double, 3, 3>* rotation3DY(double degrees);
	static Matrix<double, 3, 3>* rotation3DZ(double degrees);

	// Матрицы аксонометрической проекции

	// Изометрическая
	static Matrix<double, 3, 3>* projectionIsometric();
	static Matrix<double, 4, 4>* h_projectionIsometric();
	// Диметрическая
	static Matrix<double, 3, 3>* projectionDimetric();
	static Matrix<double, 4, 4>* h_projectionDimetric();
	// Проекция Кабине
	static Matrix<double, 3, 3>* projectionCabinet();
	static Matrix<double, 4, 4>* h_projectionCabinet();


	// Матрица отображения декартовой СК в экранную СК
	static Matrix<double, 3, 3>* cartesian2DToScreenMapping(
		double xmin, double xmax, double ymin, double ymax, double width, double height, bool equalScale = false);
};

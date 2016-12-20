#include "matrix_util.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

// Матрицы отражения
Matrix<double, 3, 3>* MatrixUtil::h_reflection2DOX() {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 1);
	res->set(1, 1, -1);
	res->set(2, 2, 1);
	return res;
}
Matrix<double, 3, 3>* MatrixUtil::h_reflection2DOY() {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, -1);
	res->set(1, 1, 1);
	res->set(2, 2, 1);
	return res;
}

// Матрицы масштабирования
Matrix<double, 3, 3>* MatrixUtil::h_scaling2D(double sx, double sy) {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, sx);
	res->set(1, 1, sy);
	res->set(2, 2, 1);
	return res;
}

// Матрицы переноса
Matrix<double, 3, 3>* MatrixUtil::h_translation2D(double dx, double dy) {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 1);
	res->set(1, 1, 1);
	res->set(2, 0, dx);
	res->set(2, 1, dy);
	res->set(2, 2, 1);
	return res;
}

// Перевод градусов в радианы
double degToRad(double degrees) {
	return M_PI / 180.0 * degrees;
}

// Матрица поворота вокруг ОХ
//
// 1  0     0
// 0  cos  -sin
// 0  sin   cos
//
Matrix<double, 3, 3>* MatrixUtil::rotation3DX(double degrees) {
	double angleRad = degToRad(degrees);
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 1);
	res->set(1, 1, cos(angleRad));
	res->set(1, 2, -sin(angleRad));
	res->set(2, 1, sin(angleRad));
	res->set(2, 2, cos(angleRad));
	return res;
}

// Матрица поворота вокруг ОY
//
// cos  0  -sin
// 0    1   0  
// sin  0   cos
//
Matrix<double, 3, 3>* MatrixUtil::rotation3DY(double degrees) {
	double angleRad = degToRad(degrees);
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, cos(angleRad));
	res->set(0, 2, -sin(angleRad));
	res->set(1, 1, 1);
	res->set(2, 0, sin(angleRad));
	res->set(2, 2, cos(angleRad));
	return res;
}

// Матрица поворота вокруг ОZ
//
// cos  -sin   0
// sin   cos   0
// 0     0     1
//
Matrix<double, 3, 3>* MatrixUtil::rotation3DZ(double degrees) {
	double angleRad = degToRad(degrees);
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, cos(angleRad));
	res->set(0, 1, -sin(angleRad));
	res->set(1, 0, sin(angleRad));
	res->set(1, 1, cos(angleRad));
	res->set(2, 2, 1);
	return res;
}



// Матрица изометрической проекции
//
// 0.707   0.408  0  0
// 0       0.817  0  0
// 0.707  -0.408  0  0
// 0       0      0  1
//
Matrix<double, 3, 3>* MatrixUtil::projectionIsometric() {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 0.707);
	res->set(0, 1, 0.408);
	res->set(1, 1, 0.817);
	res->set(2, 0, 0.707);
	res->set(2, 1, -0.408);
	return res;
}
Matrix<double, 4, 4>* MatrixUtil::h_projectionIsometric() {
	Matrix<double, 4, 4>* res = new Matrix<double, 4, 4>();
	res->set(0, 0, 0.707);
	res->set(0, 1, 0.408);
	res->set(1, 1, 0.817);
	res->set(2, 0, 0.707);
	res->set(2, 1, -0.408);
	res->set(3, 3, 1);
	return res;
}

// Матрица диметрической проекции
//
// 0.926   0.134  0  0
// 0       0.935  0  0
// 0.378  -0.327  0  0
// 0       0      0  1
//
Matrix<double, 3, 3>* MatrixUtil::projectionDimetric() {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 0.926);
	res->set(0, 1, 0.134);
	res->set(1, 1, 0.935);
	res->set(2, 0, 0.378);
	res->set(2, 1, -0.327);
	return res;
}
Matrix<double, 4, 4>* MatrixUtil::h_projectionDimetric() {
	Matrix<double, 4, 4>* res = new Matrix<double, 4, 4>();
	res->set(0, 0, 0.926);
	res->set(0, 1, 0.134);
	res->set(1, 1, 0.935);
	res->set(2, 0, 0.378);
	res->set(2, 1, -0.327);
	res->set(3, 3, 1);
	return res;
}

// Матрица проекции Кабине
//
//  1      0     0  0
//  0      1     0  0
// -0.35  -0.35  0  0
//  0      0     0  1
//
Matrix<double, 3, 3>* MatrixUtil::projectionCabinet() {
	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>();
	res->set(0, 0, 1);
	res->set(1, 1, 1);
	res->set(2, 0, -0.35);
	res->set(2, 1, -0.35);
	return res;
}
Matrix<double, 4, 4>* MatrixUtil::h_projectionCabinet() {
	Matrix<double, 4, 4>* res = new Matrix<double, 4, 4>();
	res->set(0, 0, 1);
	res->set(1, 1, 1);
	res->set(2, 0, -0.35);
	res->set(2, 1, -0.35);
	res->set(3, 3, 1);
	return res;
}


// Матрица отображения декартовых координат в экранные
//
// Порядок действий:
//
//   A(xmin, ymax)           B(xmax, ymax)
//         |-----------------------|
//         |                       |
//         |                       |
//         |                       |
//         |                       |
//         |-----------------------|
//   C(xmin, ymin)           D(xmax, ymin)
//
//   1) reflectOX =  (1   0)
//                   (0  -1)
//
//      A -> (xmin, -ymax)
//      B -> (xmax, -ymax)
//      C -> (xmin, -ymin)
//      D -> (xmax, -ymax)
//
//   2) dx = xmax - xmin
//      dy = ymax - ymin
//
//      translate =  ( 1     0     0)
//                   ( 0     1     0)
//                   (-dx/2  dy/2  1)
//
//      A -> (xmin - dx / 2, -ymax + dy / 2)
//      B -> (xmax - dx / 2, -ymax + dy / 2)
//      C -> (xmin - dx / 2, -ymin + dy / 2)
//      D -> (xmax - dx / 2, -ymin + dy / 2)
//
//   3) kx = width / dx
//      ky = height / dy
//      k = min(kx, ky)
//
//      scale =  (kx  0 )
//               (0   ky)
//
//      A -> ((xmin - dx / 2) * kx, (-ymax + dy / 2) * ky)
//      B -> ((xmax - dx / 2) * kx, (-ymax + dy / 2) * ky)
//      C -> ((xmin - dx / 2) * kx, (-ymin + dy / 2) * ky)
//      D -> ((xmax - dx / 2) * kx, (-ymin + dy / 2) * ky)
//
//   4) tx = (xmin - dx / 2) * kx
//      ty = (ymin + ymax) / 2 * ky
//
//      translate =  ( 1   0   0)
//                   ( 0   1   0)
//                   (-tx  ty  0)
//
//      A -> (0, 0)
//      B -> (width, 0)
//      C -> (0, height)
//      D -> (width, height)
//
Matrix<double, 3, 3>* MatrixUtil::cartesian2DToScreenMapping(
	double xmin, double xmax, double ymin, double ymax, double width, double height, bool equalScale) {

	double dx = xmax - xmin;
	double dy = ymax - ymin;
	double kx = width / dx;
	double ky = height / dy;
	if (equalScale) {
		double k = std::min(kx, ky);
		kx = k;
		ky = k;
	}
	double tx = (xmin - dx / 2) * kx;
	double ty = (ymin + ymax) / 2 * ky;

	Matrix<double, 3, 3>* refl = h_reflection2DOX();
	Matrix<double, 3, 3>* tr1 = h_translation2D(-dx/2, dy/2);
	Matrix<double, 3, 3>* sca = h_scaling2D(kx, ky);
	Matrix<double, 3, 3>* tr2 = h_translation2D(-tx, ty);

	Matrix<double, 3, 3>* res = new Matrix<double, 3, 3>(((*refl * *tr1) * *sca) * *tr2);
	return res;
}
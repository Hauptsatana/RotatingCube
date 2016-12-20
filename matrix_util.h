#pragma once
#include "matrix.h"

class MatrixUtil 
{
public:
	// h_ - ���������� ������� (��������� ���������� h)

	// ������� ���������
	static Matrix<double, 3, 3>* h_reflection2DOX();
	static Matrix<double, 3, 3>* h_reflection2DOY();

	// ������� ���������������
	static Matrix<double, 3, 3>* h_scaling2D(double sx, double sy);

	// ������� ��������
	static Matrix<double, 3, 3>* h_translation2D(double dx, double dy);

	// ������� �������� ������ ����
	static Matrix<double, 3, 3>* rotation3DX(double degrees);
	static Matrix<double, 3, 3>* rotation3DY(double degrees);
	static Matrix<double, 3, 3>* rotation3DZ(double degrees);

	// ������� ����������������� ��������

	// ��������������
	static Matrix<double, 3, 3>* projectionIsometric();
	static Matrix<double, 4, 4>* h_projectionIsometric();
	// �������������
	static Matrix<double, 3, 3>* projectionDimetric();
	static Matrix<double, 4, 4>* h_projectionDimetric();
	// �������� ������
	static Matrix<double, 3, 3>* projectionCabinet();
	static Matrix<double, 4, 4>* h_projectionCabinet();


	// ������� ����������� ���������� �� � �������� ��
	static Matrix<double, 3, 3>* cartesian2DToScreenMapping(
		double xmin, double xmax, double ymin, double ymax, double width, double height, bool equalScale = false);
};

#pragma once
#include "point3d.h"
#include <utility>

// ����� � ���������� ����������� - ������ ����� � ������ ����� ����
class Frame3D {

private:
	int checkPoint(int index) const;
	int checkLink(int index) const;

protected:
	Point3D** points;	// ������ ������ �� �����
	int pcount;			
	int* links;		// ������ �������� ����� �������
	int lcount;
	

public:
	Frame3D() {}
	Frame3D(Point3D** points, int pcount, int* links, int lcount);
	Frame3D(const Frame3D& frame);
	//~Frame3D();

	// ����� � �������
	Point3D* getPoint(int index) const;
	int getPointsCount() const;
	int* getLink(int index) const;
	int getLinksCount() const;

	// ��������������
	void selfTransform(const Matrix<double, 3, 3>& matr);
	void h_selfTransform(const Matrix<double, 4, 4>& matr);

};
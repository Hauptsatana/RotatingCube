#pragma once
#include "frame3d.h"

// ���, ����� �������� ���� ����� ������������ ������
class Cube : public Frame3D {

public:
	Cube() : Cube(1) {}

	Cube(double dimension) {

		// �������
		pcount = 8;
		points = new Point3D*[8];
		// ������ �����
		points[0] = new Point3D(0, 0, 0);
		points[1] = new Point3D(dimension, 0, 0);
		points[2] = new Point3D(dimension, 0, dimension);
		points[3] = new Point3D(0, 0, dimension);
		// ������� �����
		points[4] = new Point3D(0, dimension, 0);
		points[5] = new Point3D(dimension, dimension, 0);
		points[6] = new Point3D(dimension, dimension, dimension);
		points[7] = new Point3D(0, dimension, dimension);
		
		// �����
		lcount = 12;
		links = new int[24];
		// ��� ������ �� 4 �����
		for (int i = 0; i < 4; i++) {
			// ������ �����
			links[2 * i] = i;
			links[2 * i + 1] = (i + 1) % 4;
			// ������� �����
			links[2 * i + 8] = i + 4;
			links[2 * i + 9] = ((i + 5) % 4) + 4;
			// ������� �����
			links[2 * i + 16] = i;
			links[2 * i + 17] = i + 4;
		}
	}

};
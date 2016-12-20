#pragma once
#include "frame3d.h"

// Координатные прямая - направляющие
class Guides3D : public Frame3D {

public:
	Guides3D() : Guides3D(1) {}
	Guides3D(double dimension) {
		// Вершины
		pcount = 4;
		points = new Point3D*[4];
		points[0] = new Point3D();
		points[1] = new Point3D(dimension, 0, 0);
		points[2] = new Point3D(0, dimension, 0);
		points[3] = new Point3D(0, 0, dimension);
		// Отрезки - координатные прямые
		lcount = 3;
		links = new int[6];
		for (int i = 0; i < 3; i++) {
			links[2 * i] = 0;
			links[2 * i + 1] = i + 1;
		}
	}
};

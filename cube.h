#pragma once
#include "frame3d.h"

// Куб, ребра которого идут вдоль координатных прямых
class Cube : public Frame3D {

public:
	Cube() : Cube(1) {}

	Cube(double dimension) {

		// Вершины
		pcount = 8;
		points = new Point3D*[8];
		// Нижняя грань
		points[0] = new Point3D(0, 0, 0);
		points[1] = new Point3D(dimension, 0, 0);
		points[2] = new Point3D(dimension, 0, dimension);
		points[3] = new Point3D(0, 0, dimension);
		// Верхняя грань
		points[4] = new Point3D(0, dimension, 0);
		points[5] = new Point3D(dimension, dimension, 0);
		points[6] = new Point3D(dimension, dimension, dimension);
		points[7] = new Point3D(0, dimension, dimension);
		
		// Ребра
		lcount = 12;
		links = new int[24];
		// Три группы по 4 ребра
		for (int i = 0; i < 4; i++) {
			// Нижняя грань
			links[2 * i] = i;
			links[2 * i + 1] = (i + 1) % 4;
			// Верхняя грань
			links[2 * i + 8] = i + 4;
			links[2 * i + 9] = ((i + 5) % 4) + 4;
			// Боковые ребра
			links[2 * i + 16] = i;
			links[2 * i + 17] = i + 4;
		}
	}

};
#pragma once
#include "point2d.h"

// Структура для обработанного остова
struct ProcessedFrame {
	double xmin;			// Общие границы остова
	double xmax;
	double ymin;
	double ymax;
	Point2D** flatPoints;	// Спроецированные на плоскость точки
	int pcount;

	ProcessedFrame() = default;
	ProcessedFrame(double xmin, double xmax, double ymin, double ymax, Point2D** flatPoints, int pcount);
	ProcessedFrame(const ProcessedFrame& pf);
	~ProcessedFrame();
};

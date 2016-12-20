#pragma once
#include "point2d.h"

// ��������� ��� ������������� ������
struct ProcessedFrame {
	double xmin;			// ����� ������� ������
	double xmax;
	double ymin;
	double ymax;
	Point2D** flatPoints;	// ��������������� �� ��������� �����
	int pcount;

	ProcessedFrame() = default;
	ProcessedFrame(double xmin, double xmax, double ymin, double ymax, Point2D** flatPoints, int pcount);
	ProcessedFrame(const ProcessedFrame& pf);
	~ProcessedFrame();
};

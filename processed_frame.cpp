#include "processed_frame.h"

ProcessedFrame::ProcessedFrame(double xmin, double xmax, double ymin, double ymax, Point2D** flatPoints, int pcount) {
	this->xmin = xmin;
	this->xmax = xmax;
	this->ymin = ymin;
	this->ymax = ymax;
	this->flatPoints = new Point2D*[pcount];
	for (int i = 0; i < pcount; i++) {
		this->flatPoints[i] = new Point2D(*flatPoints[i]);
	}
}

ProcessedFrame::ProcessedFrame(const ProcessedFrame& pf) {
	this->xmin = pf.xmin;
	this->xmax = pf.xmax;
	this->ymin = pf.ymin;
	this->ymax = pf.ymax;
	this->pcount = pf.pcount;
	this->flatPoints = new Point2D*[pcount];
	for (int i = 0; i < pcount; i++) {
		this->flatPoints[i] = new Point2D(*(pf.flatPoints[i]));
	}
}

ProcessedFrame::~ProcessedFrame() {
	for (int i = 0; i < pcount; i++) {
		delete flatPoints[i];
	}
	delete[] flatPoints;
}
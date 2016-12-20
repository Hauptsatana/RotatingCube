#pragma once

#ifndef RENDER_AREA_H
#define RENDER_AREA_H

#include <QFrame>
#include <QPainter>
#include "frame3d.h"
#include "processed_frame.h"
#include "guides3d.h"
#include <vector>

// ������� ��������
enum Projection { Isometric, Dimetric, Cabinet };

// ��������� ��� ��������� ��������
class RenderArea : public QFrame 
{
	Q_OBJECT

public:
	// �������� ������ �� ���������
	static ProcessedFrame* processFrame(const Frame3D& frame, Matrix<double, 4, 4>& h_mproj);

private:
	Matrix<double, 4, 4> h_mproj;		// ������� 3D-2D ��������
	
	Guides3D guides = Guides3D(2.5);	// ������������ ���
	std::vector<Frame3D*> frames;		// ������, ������� ���������� ����������

	bool equalScale = true;		// ���������� ������� �� ����

	bool rotX = false;			// ���� �������� ������ ���� ���������
	bool rotY = false;
	bool rotZ = false;
	double angleX = 0;					
	double angleY = 0;
	double angleZ = 0;

public:
	RenderArea(QWidget* parent = 0);

	void addFrame(Frame3D* frame); // �������� ����� ��� ���������
	void setProjection(Projection projection);	// ���������� ������� ��������
	

public slots:
	// ��������� ��������� �������������� � ����������
	void transformAndRender();

	// ���� ��������
	void setRotX(bool rotX);
	void setRotY(bool rotY);
	void setRotZ(bool rotZ);
	void setAngleX(double angleX);
	void setAngleY(double angleY);
	void setAngleZ(double angleZ);

protected:
	void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

};


#endif // RENDER_AREA_H

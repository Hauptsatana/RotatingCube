#pragma once

#ifndef RENDER_AREA_H
#define RENDER_AREA_H

#include <QFrame>
#include <QPainter>
#include "frame3d.h"
#include "processed_frame.h"
#include "guides3d.h"
#include <vector>

// Матрицы проекций
enum Projection { Isometric, Dimetric, Cabinet };

// Компонент для отрисовки объектов
class RenderArea : public QFrame 
{
	Q_OBJECT

public:
	// Проекция остова на плоскость
	static ProcessedFrame* processFrame(const Frame3D& frame, Matrix<double, 4, 4>& h_mproj);

private:
	Matrix<double, 4, 4> h_mproj;		// Матрица 3D-2D проекции
	
	Guides3D guides = Guides3D(2.5);	// Координатные оси
	std::vector<Frame3D*> frames;		// Остовы, которые необходимо отрисовать

	bool equalScale = true;		// Одинаковый масштаб по осям

	bool rotX = false;			// Углы вращения вокруг осей координат
	bool rotY = false;
	bool rotZ = false;
	double angleX = 0;					
	double angleY = 0;
	double angleZ = 0;

public:
	RenderArea(QWidget* parent = 0);

	void addFrame(Frame3D* frame); // Добавить остов для отрисовки
	void setProjection(Projection projection);	// Установить матрицу проекции
	

public slots:
	// Выполнить следующее преобразование и отрисовать
	void transformAndRender();

	// Углы вращения
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

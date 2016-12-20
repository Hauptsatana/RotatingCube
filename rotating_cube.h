#ifndef ROTATING_CUBE_H
#define ROTATING_CUBE_H

#include <QtWidgets/QMainWindow>
#include "ui_rotating_cube.h"

#include <qtimer.h>

class RotatingCube : public QMainWindow
{
	Q_OBJECT // Если не добавить, то не будут обрабатываться события

private:
	Ui::RotatingCubeClass ui;
	QTimer* timer = new QTimer();	// Таймер, по таймауту которого будет происходить отрисовка


public:
	RotatingCube(QWidget *parent = 0);
	~RotatingCube();

public slots:
	void toggleRendering(bool enable);
	void resetTimerInterval(int value);
	void updateProjectionMatrix();

};

#endif // ROTATING_CUBE_H

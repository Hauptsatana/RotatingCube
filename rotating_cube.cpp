#include "rotating_cube.h"
#include "guides3d.h"

RotatingCube::RotatingCube(QWidget *parent)
	: QMainWindow(parent) {

	// Настройка интерфейса формы
	ui.setupUi(this);

	// Обработка событий

	// Запуск по таймеру
	connect(ui.pushButton, SIGNAL(toggled(bool)), this, SLOT(toggleRendering(bool)));
	connect(timer, SIGNAL(timeout()), ui.renderArea, SLOT(transformAndRender()));
	// Таймаут у таймера
	connect(ui.timeoutSlider, SIGNAL(valueChanged(int)), this, SLOT(resetTimerInterval(int)));	
	// Изменение углов
	connect(ui.chbox_RotateX, SIGNAL(toggled(bool)), ui.renderArea, SLOT(setRotX(bool)));
	connect(ui.chbox_RotateY, SIGNAL(toggled(bool)), ui.renderArea, SLOT(setRotY(bool)));
	connect(ui.chbox_RotateZ, SIGNAL(toggled(bool)), ui.renderArea, SLOT(setRotZ(bool)));
	connect(ui.dspn_AngleX, SIGNAL(valueChanged(double)), ui.renderArea, SLOT(setAngleX(double)));
	connect(ui.dspn_AngleY, SIGNAL(valueChanged(double)), ui.renderArea, SLOT(setAngleY(double)));
	connect(ui.dspn_AngleZ, SIGNAL(valueChanged(double)), ui.renderArea, SLOT(setAngleZ(double)));
	// Изменение проекции
	connect(ui.rbtn_Cabinet, SIGNAL(clicked()), this, SLOT(updateProjectionMatrix()));
	connect(ui.rbtn_Dimetric, SIGNAL(clicked()), this, SLOT(updateProjectionMatrix()));
	connect(ui.rbtn_Isometric, SIGNAL(clicked()), this, SLOT(updateProjectionMatrix()));

	// Начальные условия
	timer->setInterval(ui.timeoutSlider->value());
	ui.renderArea->setRotX(ui.chbox_RotateX->isChecked());
	ui.renderArea->setRotY(ui.chbox_RotateY->isChecked());
	ui.renderArea->setRotZ(ui.chbox_RotateZ->isChecked());
	ui.renderArea->setAngleX(ui.dspn_AngleX->value());
	ui.renderArea->setAngleY(ui.dspn_AngleY->value());
	ui.renderArea->setAngleZ(ui.dspn_AngleZ->value());
}

RotatingCube::~RotatingCube() {
	delete timer;
}

void RotatingCube::toggleRendering(bool enable) {
	if (enable) {
		timer->start();
	}
	else {
		timer->stop();
	}
}

void RotatingCube::resetTimerInterval(int value) {
	timer->setInterval(value);
}

void RotatingCube::updateProjectionMatrix() {
	if (ui.rbtn_Isometric->isChecked()) {
		ui.renderArea->setProjection(Projection::Isometric);
	}
	else if (ui.rbtn_Dimetric->isChecked()) {
		ui.renderArea->setProjection(Projection::Dimetric);
	}
	else if (ui.rbtn_Cabinet->isChecked()) {
		ui.renderArea->setProjection(Projection::Cabinet);
	}
}

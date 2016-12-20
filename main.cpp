#include "rotating_cube.h"
#include <QtWidgets/QApplication>
#include "matrix_util.h"
#include "vector_h.h"
#include "cube.h"
#include "guides3d.h"

#include "math.h"

Frame3D createTestFrame();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RotatingCube w;
	w.show();

	return a.exec();
}
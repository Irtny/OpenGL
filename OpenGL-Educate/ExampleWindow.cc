/*
 * ExampleWindow.cc
 *
 *  Created on: 8 апр. 2021 г.
 *      Author: fomin
 */

#include "ExampleWindow.h"

#include <cmath>
#include "Primitives.h"

static constexpr double Pi = acos(-1.);


ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  _crate_texture("crate_tex.png")
{

}

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION); // Далее используем матрицу проекции
	gluPerspective(45., double(width()) / double(height()),
			0.1, 30.0 );
	glMatrixMode(GL_MODELVIEW); // Далее используем матрицу модел-вида
}

void ExampleWindow::render()
{
	//Очистка буфера цвета

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(
			5., 5., _camera_z,
			0.0, 0.0, 0.,
			0.0, 0., 1.0);

	glRotated(_angle, 0., 0., 1.);

//	glEnable(GL_TEXTURE_2D);
//	_crate_texture.bind();
//	_cube.draw();
	draw_cone(10);

}

void ExampleWindow::do_logic()
{
	_angle += 0.5;
	if (_angle >= 360.)
		_angle-=360.;
	_camera_z = sin(_angle / 180. * Pi) * 3.;
}

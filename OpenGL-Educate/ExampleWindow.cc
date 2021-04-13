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
  _crate_texture("crate_tex.png"),
  _roof_texture("roof_tex.png"),
  _tree_texture("tree_tex.jpg"),
  _green_texture("green_tex.jpg"),
  _white_texture("white_tex.jpg"),
  _orange_texture("orange_tex.jpg")
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
			0.1, 60.0 );
	glMatrixMode(GL_MODELVIEW); // Далее используем матрицу модел-вида
}

void ExampleWindow::render()
{
	//Очистка буфера цвета

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(
			25., 25., 3,
			0.0, 0.0, 0.,
			0.0, 0., 1.0);

	glRotated(_angle, 0., 0., 1.);
	glEnable(GL_TEXTURE_2D);

	_crate_texture.bind();
	_cube.draw();
	_roof_texture.bind();
	_roof.draw();
	glDisable(GL_TEXTURE_2D);
	_pipe.draw();

	// ёлка
	glTranslated(0.,10., -2.);
	glScaled(0.5, 0.5, 1);
	glEnable(GL_TEXTURE_2D);
	_tree_texture.bind();
	draw_cylindr(16);
	glDisable(GL_TEXTURE_2D);

	glScaled(3, 3, 1);
	glTranslated(0.,0., 1.);
	glEnable(GL_TEXTURE_2D);
	_green_texture.bind();
	draw_cone(32);

	glScaled(0.85, 0.85, 1);
	glTranslated(0.,0., 1.);
	_green_texture.bind();
	draw_cone(32);

	glScaled(0.85, 0.85, 1);
	glTranslated(0.,0., 1.);
	_green_texture.bind();
	draw_cone(32);

	glScaled(0.85, 0.85, 1);
	glTranslated(0.,0., 1.);
	_green_texture.bind();
	draw_cone(32);

	glScaled(0.85, 0.85, 1);
	glTranslated(0.,0., 1.);
	_green_texture.bind();
	draw_cone(32);
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();


	//Снеговик

	glScaled(1, 1, 0.8);
	glTranslated(0.,5., -5.);
	draw_sphere_smooth(16, 8);

	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.,0., 1.5);
	draw_sphere_smooth(16, 8);

	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.,0., 1.5);
	draw_sphere_smooth(16, 8);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glRotated(120.,1.,1.,1);
	glScaled(0.2, 0.25, 0.5);
	glTranslated(0.,0., 0.9);
	_orange_texture.bind();
	draw_cone(32);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPushMatrix();
	//Снеговик

	glScaled(1, 1, 0.8);
	glTranslated(5.,5., -5.);
	draw_sphere_smooth(16, 8);

	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.,0., 1.5);
	draw_sphere_smooth(16, 8);

	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.,0., 1.5);
	draw_sphere_smooth(16, 8);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glRotated(120.,1.,1.,1);
	glScaled(0.2, 0.25, 0.5);
	glTranslated(0.,0., 0.9);
	_orange_texture.bind();
	draw_cone(32);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	_white_texture.bind();
	draw_sphere_smooth_motion(32, 32, 2+xx, 2+yy, 0.5+zz, 0.1);
	draw_sphere_smooth_motion(32, 64, 1+xx, 2+yy, 0.2-zz, 0.1);
	draw_sphere_smooth_motion(64, 64, 2+xx, 4+yy, -0.1+zz, 0.1);
	draw_sphere_smooth_motion(32, 32, 1+xx, 2+yy, -0.5+zz, 0.1);
	draw_sphere_smooth_motion(32, 64, 3+xx, 1+yy, 0.6-zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -2+xx, -4+yy, -0.3+zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -2+xx, -3+yy, -0.5-zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -4+xx, -2+yy, -0.6+zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -3+xx, -4+yy, -0.7-zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -2+xx, -4+yy, -0.3+zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -1+xx, -0+yy, -0.2-zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -3+xx, -0+yy, -0.1+zz, 0.1);
	draw_sphere_smooth_motion(32, 16, -2+xx, -0+yy, -0.3-zz, 0.1);

	glDisable(GL_TEXTURE_2D);


}

void ExampleWindow::do_logic()
{
	_angle -= 0.5;
		if (_angle >= 360.)
			_angle -= 360.;

		zz += 0.05 * i;
		if (zz >= 0.5) i = -1;
		else if (zz <= 0) i = 1;

		if (k == 1) {
			yy -= 0.05;
			if (yy <= -4) k = 2;
		} else if (k == 2){
			xx -= 0.05;
			if (xx <= -4) k = 3;
		} else if (k == 3){
			yy += 0.05;
			if (yy >= 0) k = 4;
		} else if (k == 4){
			xx += 0.05;
			if (xx >= 0) k = 1;
		}

		_camera_z = 5 + sin(_angle / 45. * Pi) * 6.;
}

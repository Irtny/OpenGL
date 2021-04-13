/*
 * ExampleWindow.h
 *
 *  Created on: 8 апр. 2021 г.
 *      Author: fomin
 */
#pragma once
#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "Texture.h"
#include "SimpleModel.h"


class ExampleWindow: public Window {
protected:
	double _angle { 0. };
	double _camera_z { 0. };
	double zz = 0., i = 1, k = 1;
	double xx = 0, yy = 0;

	SimpleModel _cube = SimpleModel::create_cube();
	SimpleModel _roof = SimpleModel::create_roof();
	SimpleModel _pipe = SimpleModel::create_pipe();
	Texture _crate_texture;
	Texture _roof_texture;
	Texture _tree_texture;
	Texture _green_texture;
	Texture _white_texture;
	Texture _orange_texture;

public:
	ExampleWindow(	int width = DEFAULT_WIDTH,
					int height = DEFAULT_HEIGHT );
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic();
};

#endif /* EXAMPLEWINDOW_H_ */

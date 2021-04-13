/*
 * ExampleWindow.h
 *
 *  Created on: 3 ���. 2021 �.
 *      Author: ��������
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky, _sun, _meadow, _pig, _rocks, _cloud1, _cloud2, _cloud3, _house, _plane, _duck;
	int _meadow_x, _pig_x, _pig_y, _rocks_x, _sun_x,_cloud1_x, _cloud2_x, _sun_y, _cloud3_x, _house_x, _plane_x, _duck_x;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};


#endif /* EXAMPLEWINDOW_H_ */

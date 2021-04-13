/*
 * ExampleWindow.cc
 *
 *  Created on: 3 апр. 2021 г.
 *      Author: Домашний
 */

#include "ExampleWindow.h"
#include <stdexcept>
#include <SDL2/SDL_image.h>
#include <math.h>

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height), _meadow_x(0), _sun_x(0.), _sun_y(height/6), _pig_x(0), _pig_y(height/1.2), _rocks_x(0), _cloud1_x(0.),_cloud2_x(0.),  _cloud3_x(0.), _duck_x(0),
  _house_x(0), _plane_x(0)
{
	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky.png"),
			SDL_DestroyTexture);
	if (_sky == nullptr)
		throw std::runtime_error(
			std::string("Не удалось загрузить небо") +
			std::string(SDL_GetError()));

	_sun = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sun.png"),
			SDL_DestroyTexture);
	if (_sun == nullptr)
		throw std::runtime_error(
			std::string("Не удалось загрузить солнце") +
			std::string(SDL_GetError()));

	_meadow = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "meadow.png"),
				SDL_DestroyTexture);
	if (_meadow == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить поле") +
				std::string(SDL_GetError()));

	_pig = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "pig.png"),
				SDL_DestroyTexture);
	if (_pig == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить поросёнка") +
				std::string(SDL_GetError()));

	_rocks = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "rocks.png"),
				SDL_DestroyTexture);
	if (_rocks == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить горы") +
				std::string(SDL_GetError()));

	_cloud1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud1.png"),
				SDL_DestroyTexture);
	if (_cloud1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить облака") +
				std::string(SDL_GetError()));
	_cloud2 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud2.png"),
				SDL_DestroyTexture);
	if (_cloud2 == nullptr)
			throw std::runtime_error(
				std::string("Не удалось загрузить облака") +
				std::string(SDL_GetError()));
	_cloud3 = std::shared_ptr<SDL_Texture>(
					IMG_LoadTexture(_renderer.get(), "cloud3.png"),
					SDL_DestroyTexture);
	if (_cloud3 == nullptr)
			throw std::runtime_error(
				std::string("Не удалось загрузить облака") +
				std::string(SDL_GetError()));
	_house = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "house.png"),
				SDL_DestroyTexture);
	if (_house == nullptr)
			throw std::runtime_error(
				std::string("Не удалось загрузить дом") +
				std::string(SDL_GetError()));
	_plane = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "plane.png"),
				SDL_DestroyTexture);
	if (_plane == nullptr)
			throw std::runtime_error(
				std::string("Не удалось загрузить самолёт") +
				std::string(SDL_GetError()));
	_duck = std::shared_ptr<SDL_Texture>(
					IMG_LoadTexture(_renderer.get(), "duck.png"),
					SDL_DestroyTexture);
	if (_duck == nullptr)
			throw std::runtime_error(
				std::string("Не удалось загрузить утку") +
				std::string(SDL_GetError()));

}

void ExampleWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { 0, 0, width(), height() };
	SDL_Rect meadow_rect { _meadow_x, 0, width()*2, height() };
	SDL_Rect pig_rect { _pig_x, _pig_y, width()/7, height()/7 };
	SDL_Rect sun_rect { _sun_x, _sun_y , width()/12, height()/7 };
	SDL_Rect rocks_rect { _rocks_x, height()/5, width()*2, height()/2 };
	SDL_Rect cloud1_rect { _cloud1_x, 0, width()*2, height()/3 };
	SDL_Rect cloud2_rect { _cloud2_x, height()/5, width()*2, height()/3 };
	SDL_Rect cloud3_rect { _cloud3_x, height()/3, width()*2, height()/5 };
	SDL_Rect house_rect { _house_x+width()/5, height()/1.35, width()/9, height()/12 };
	SDL_Rect house_rect2 { _house_x+width(), height()/1.7, width()/6, height()/4 };
	SDL_Rect plane_rect { _plane_x+width(), height()/12, width()/5, height()/14 };
	SDL_Rect duck_rect { _duck_x, height()/3, width()/9, height()/12 };

 SDL_Rect r { 0, 456, 750,500 };
	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	SDL_RenderCopy(_renderer.get(), _cloud3.get(), nullptr, &cloud3_rect);
	SDL_RenderCopy(_renderer.get(), _rocks.get(), nullptr, &rocks_rect);
	SDL_RenderCopy(_renderer.get(), _meadow.get(), nullptr, &meadow_rect);
	SDL_RenderCopy(_renderer.get(), _duck.get(), nullptr, &duck_rect);
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud2_rect);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud1_rect);
	SDL_RenderCopy(_renderer.get(), _house.get(), &r, &house_rect);
	SDL_RenderCopy(_renderer.get(), _house.get(), nullptr, &house_rect2);
	SDL_RenderCopy(_renderer.get(), _plane.get(), nullptr, &plane_rect);
	SDL_RenderCopy(_renderer.get(), _pig.get(), nullptr, &pig_rect);







}

void ExampleWindow::do_logic()
{


	_meadow_x-=5;
	if(_meadow_x<=-width())
		_meadow_x=0;

	_rocks_x-=1;
		if(_rocks_x<=-width())
			_rocks_x=-width()/3;

	_sun_x+=1;
			if(_sun_x>=width())
				_sun_x=-width()/6;

	_cloud1_x-=4;
			if(_cloud1_x<=-width())
				_cloud1_x=0;

	_cloud2_x-=3;
			if(_cloud2_x<=-width())
				_cloud2_x=0;

	_cloud3_x-=2;
			if(_cloud3_x<=-width())
				_cloud3_x=0;
	_house_x-=5;
			if(_house_x<=-width()*1.15)
				_house_x=width();
	_plane_x-=6;
			if(_plane_x<=-width()*1.2)
				_plane_x=width()/3;
	_pig_x+=2;
			if(_pig_x>=width())
				_pig_x=-width()/6;
			if(_pig_x==0)
				_pig_x+=2;
			if(_pig_y<=height()/1.3)
				_pig_y+=2;
			if(_pig_y>=height()/1.15)
				_pig_y-=2;

	_duck_x+=3;
			if(_duck_x>=width()*1.1)
				_duck_x=-width()/6;



}

void ExampleWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_DOWN])
		_pig_y += 2;
	if (keys[SDL_SCANCODE_UP])
		_pig_y -= 2;
	if (keys[SDL_SCANCODE_LEFT])
		_pig_x -= 4;
	if (keys[SDL_SCANCODE_RIGHT])
		_pig_x += 2;
}

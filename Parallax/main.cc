/*
 * main.cc
 *
 *  Created on: 3 апр. 2021 г.
 *      Author: Домашний
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include <SDL2/SDL_main.h>

#include "ExampleWindow.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try{

		ExampleWindow w;

		w.main_loop();




	} catch(std::exception & e){
		std::cerr <<"Во время работы произошло исключение: "
				<< std::endl
				<< e.what()
				<< std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Произошло неизвестное исключение "
				"НЕ ПОНЯТНО!" <<std::endl;
		return 1;
	}


	return 0;
}



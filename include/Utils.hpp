#ifndef UITLS_HPP
#define UITLS_HPP
#pragma once
#include <SDL2/SDL.h>

namespace utils{
	float higherTimeInSeconds(){
	float t = SDL_GetTicks();
		t*=0.001f;
		return t;
}};

#endif
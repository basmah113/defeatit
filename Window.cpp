#include "Window.h"
#include <SDL_image.h>
#include <iostream>
#include "rect.h"

bool collision(SDL_Rect* rect, SDL_Rect* square)
{
	if (rect->y >= square->y + square->h)
		return 0;
	if (rect->x >= square->x + square->w)
		return 0;
	if (rect->y + rect->h <= square->y)
		return 0;
	if (rect->x + rect->w <= square->x)
		return 0;
	return 1;
}

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const std::string& title, int width, int height) :
_title(title), _width(width), _height(height)
{
	_closed = !init();
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL.\n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Failed to initialize SDL_image.\n";
		return false;
	}



	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0
	);

	if (_window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return 0;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return 0;
	}

	return true;
}

void Window::pollEvents(SDL_Event &event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}

	default:
		break;
	}
	
}

void Window::clear() const {
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
	SDL_RenderClear(renderer);

	SDL_Rect square;

	square.w = 90;
	square.h = 120;
	square.x = _width / 20;
	square.y = _height / 50;

	SDL_SetRenderDrawColor(renderer, 139, 0, 139, 255);
	SDL_RenderFillRect(renderer, &square);
	

	

	SDL_RenderPresent(renderer);
}
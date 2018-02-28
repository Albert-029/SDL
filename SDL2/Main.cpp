#include "SDL/Include/SDL.h"
#include <stdio.h>
#pragma comment(lib, "SDL/Libraries/SDL2.lib")
#pragma comment(lib, "SDL/Libraries/SDL2main.lib")
SDL_Window* window;
SDL_Surface* surface;
int init() {
	window = NULL;
	surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL_Init, Error: %d", SDL_GetError());
		return -1;
	}
	window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 600, SDL_WINDOW_SHOWN/*,SDL_WINDOW_BORDERLESS*/);
	if (window == NULL) {
		printf("SDL_CreateWindow, Error: %d", SDL_GetError());
		return -1;
	}
	surface = SDL_GetWindowSurface(window);
	return 0;
}
void Cleanup() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
int main(int argc, char*argv[]) {
	init();
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 142, 204));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);
	Cleanup();
	return 0;
}
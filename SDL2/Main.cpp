#include "SDL/Include/SDL.h"
#include <iostream>
using namespace std;
#pragma comment(lib, "SDL/Libraries/SDL2.lib")
#pragma comment(lib, "SDL/Libraries/SDL2main.lib")
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 680;
int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* blockRender = NULL;
	SDL_Rect rect;
	rect.w = 80;
	rect.h = 70;
	rect.x = 0;
	rect.y = 0;
	SDL_Event e;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else
	{
		window = SDL_CreateWindow("El cuadrado depre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		}
		else
		{
			blockRender = SDL_CreateRenderer(window, -1, 0);
			
			while (1) {
				if (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						break;
					}
				}
				while (rect.x < 1280 || rect.y < 680) {
					rect.x++;
					rect.y++;
					if (rect.x == 1280) {
						rect.x--;
					}
					else if (rect.x == 0) {
						rect.x++;
					}
					else if (rect.y == 680) {
						rect.y--;
					}
					else if (rect.y == 0) {
						rect.y++;
					}
					SDL_SetRenderDrawColor(blockRender, 0, 0, 255, 255);
					SDL_RenderClear(blockRender);
					SDL_SetRenderDrawColor(blockRender, 255, 0, 0, 255);
					SDL_RenderFillRect(blockRender, &rect);
					SDL_RenderPresent(blockRender);
					SDL_Delay(5);
				}
								
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
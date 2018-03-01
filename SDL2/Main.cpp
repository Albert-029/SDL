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
	int dirx = 1;
	int diry = 1;
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
				while (rect.x <= 1280 && rect.x >= 0 && rect.y >= 0 && rect.y <= 680) {
					rect.x = rect.x + dirx;
					if (rect.x == 1200 || rect.x == 0) {
							dirx = dirx * -1;
					}
					rect.y = rect.y + diry;
					if (rect.y == 0 || rect.y == 610) {
						diry = diry * -1;
					}
					SDL_SetRenderDrawColor(blockRender, 0, 0, 255, 255);
					SDL_RenderClear(blockRender);
					SDL_SetRenderDrawColor(blockRender, 255, 0, 0, 255);
					SDL_RenderFillRect(blockRender, &rect);
					SDL_RenderPresent(blockRender);
					SDL_Delay(2.5);
				}			
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
/*
	int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
		return 1;
	}
	SDL_Window *win = SDL_CreateWindow("Rendering to a texture!", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	//Put your own bmp image here
	SDL_Surface *bmpSurf = SDL_LoadBMP("../res/image.bmp");
	SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(renderer, bmpSurf);
	SDL_FreeSurface(bmpSurf);

	//Make a target texture to render too
	SDL_Texture *texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WIN_WIDTH, WIN_HEIGHT);
	
	//Now render to the texture
	SDL_SetRenderTarget(renderer, texTarget);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bmpTex, NULL, NULL);
	//Detach the texture
	SDL_SetRenderTarget(renderer, NULL);

	//Now render the texture target to our screen, but upside down
	SDL_RenderClear(renderer);
	SDL_RenderCopyEx(renderer, texTarget, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
	SDL_RenderPresent(renderer);

	SDL_Delay(1000);
	SDL_DestroyTexture(texTarget);
	SDL_DestroyTexture(bmpTex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
	}
*/
}
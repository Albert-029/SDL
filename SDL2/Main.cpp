#include "SDL/Include/SDL.h"
#include "SDL/Include/SDL_image.h"
#include "SDL/Include/SDL_mixer.h"
#pragma comment(lib, "SDL/Libraries/SDL2.lib")
#pragma comment(lib, "SDL/Libraries/SDL2main.lib")
#pragma comment(lib, "SDL_Image/Libraries/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/Libraries/SDL2_mixer.lib")
int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* blockRender = NULL;
	SDL_Event e;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Rect rect;
	rect.w = 80;
	rect.h = 70;
	rect.x = 250;
	rect.y = 250;
	SDL_Rect blast[1];
	int vel = 1, shots = 0, i;
	bool quit = false, mleft = false, mright = false, mup = false, mdown = false;
	window = SDL_CreateWindow("Red Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 680, SDL_WINDOW_BORDERLESS);
	blockRender = SDL_CreateRenderer(window, -1, 0);
	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					mleft = false;
					break;
				case SDLK_RIGHT:
					mright = false;
					break;
				case SDLK_UP:
					mup = false;
					break;
				case SDLK_DOWN:
					mdown = false;
					break;
				case SDLK_SPACE:
					
					break;
				}
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					mleft = true;
					break;
				case SDLK_RIGHT:
					mright = true;
					break;
				case SDLK_UP:
					mup = true;
					break;
				case SDLK_DOWN:
					mdown = true;
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				case SDLK_SPACE:
					blast[shots].x = rect.x + 80;
					blast[shots].y = rect.y + 30;
					shots++;
					break;
				}
			}
		}
		if (rect.x == 0) {
			mleft = false;
		}
		if (rect.x == 1200) {
			mright = false;
		}
		if (rect.y == 0) {
			mup = false;
		}
		if (rect.y == 610) {
			mdown = false;
		}
		if (mleft == true) {
			rect.x -= vel;
			
		}
		if (mright == true) {
			rect.x += vel;
			
		}
		if (mup == true) {
			rect.y -= vel;
			
		}
		if (mdown == true) {
			rect.y += vel;
			
		}
		SDL_SetRenderDrawColor(blockRender, 0, 255, 0, 255);
		for (int i = 0; i <= shots; ++i)
		{
			blast[i].w = 30;
			blast[i].h = 10;
			blast[i].x += vel;
			SDL_RenderFillRect(blockRender, &blast[i]);
			if (blast[i].x < 1280)
			{
				SDL_RenderCopy(blockRender, NULL, NULL, &blast[i]);
			}
		}
		SDL_RenderPresent(blockRender);
		SDL_SetRenderDrawColor(blockRender, 0, 0, 255, 255);
		SDL_RenderClear(blockRender);
		SDL_SetRenderDrawColor(blockRender, 255, 0, 0, 255);
		SDL_RenderFillRect(blockRender, &rect);
		SDL_RenderPresent(blockRender);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
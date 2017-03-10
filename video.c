#include "video.h"
#include "common.h"
#include <SDL/SDL.h>

SDL_Surface *real_screen;
extern Color palette[];

void init_sdl(){
	SDL_Init(SDL_INIT_VIDEO);
	real_screen = SDL_SetVideoMode(SCR_WIDTH, SCR_HEIGHT, 8, 
			SDL_HWSURFACE | SDL_HWPALETTE | SDL_HWACCEL | SDL_ASYNCBLIT);
	SDL_SetPalette(real_screen, SDL_LOGPAL | SDL_PHYSPAL, (void *)&palette, 0, 256);
	SDL_WM_SetCaption("NEMU", NULL);
}

void prepare_buffer(){
	for(int i = 0; i < SCR_WIDTH * SCR_HEIGHT; i++)
		((char *)(real_screen->pixels))[i] = 0;
}

void draw_pixel(int x,int y,char color){
	((char *)(real_screen->pixels))[x * SCR_WIDTH + y] = color;
}

void display_buffer(){
	SDL_Flip(real_screen);
}

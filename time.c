#include "time.h"
#include "common.h"
#include "SDL/SDL.h"
#include <stdio.h>

extern volatile int tick;
bool IF = 1;

Uint32 tick_add(unsigned int interval,void *param){ 
        tick++;
        return interval;
}

void clock_init(){
	SDL_Init(SDL_INIT_TIMER);
	Uint32 time = 0;
	SDL_TimerID timer = SDL_AddTimer(HZ/10,tick_add,&time);
}

void wait_intr(){
	int now = tick;
	while(1){
		if((tick != now || listen_keyboard()) && (IF == 1))
			break;
	}
}

void cli(){
    IF = 0;
}

void sti(){
    IF = 1;
}

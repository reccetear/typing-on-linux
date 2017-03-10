#include "common.h"
#include "time.h"
#include "draw.h"
#include <string.h>

volatile int tick = 0;

static int real_fps;
void set_fps(int value){
    real_fps = value;
}

int get_fps(){
    return real_fps;
}

int main (){
    int now = 0;
    int target = 0;
    bool redraw = false;
    int num_draw = 0;
    init_sdl();
    clock_init();
    while(1){
	wait_intr();
        cli();
        if(now == tick)
        {
            sti();
            continue;
        }
        target = tick;
        sti();
        redraw = false;
        while(update_keypress());
        
        while(now < target){
            if(now % (HZ / CHARACTER_PER_SECOND) == 0){
                create_new_letter();
            }
            if(now % (HZ / UPDATE_PER_SECOND) == 0){
                update_letter_pos();
            }
            if(now % (HZ / FPS) ==0){
                redraw = true;
            }
            if(now % (HZ / 2) == 0){
                int now_fps = num_draw * 2 + 1;
                if(now_fps > FPS)
                    now_fps = FPS;
                set_fps(now_fps);
                num_draw = 0;
            }
            now++;
        }
        if(redraw){
            num_draw++;
            redraw_screen();
        }
    }
}

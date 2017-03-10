#include "common.h"
#include "SDL/SDL.h"
#include <stdio.h>

/* a-z对应的键盘扫描码 */
static int letter_code[] = {
	SDLK_a, SDLK_b, SDLK_c, SDLK_d, SDLK_e, SDLK_f, SDLK_g, SDLK_h, SDLK_i, SDLK_j,SDLK_k, SDLK_l, SDLK_m, SDLK_n, SDLK_o, SDLK_p, SDLK_q, SDLK_r, SDLK_s, SDLK_t,SDLK_u, SDLK_v, SDLK_w, SDLK_x, SDLK_y, SDLK_z
};
/* 对应键按下的标志位 */
static bool letter_pressed[26];

void
press_key(int scan_code) {
	int i;
	for (i = 0; i < 26; i ++) {
		if (letter_code[i] == scan_code) {
			letter_pressed[i] = true;
		}
	}
}

void
release_key(int index) {
	letter_pressed[index] = false;
}

bool
query_key(int index) {
	return letter_pressed[index];
}

/* key_code保存了上一次键盘事件中的扫描码 */
static volatile int key_code = 0;

int last_key_code(void) {
	return key_code;
}

bool
listen_keyboard() {
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			key_code = event.key.keysym.sym;
			press_key(key_code);
			return true;
		}
	}
	return false;
}


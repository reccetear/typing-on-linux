#ifndef common_h
#define common_h

#define HZ 100
#define FPS 30
#define CHARACTER_PER_SECOND 3
#define UPDATE_PER_SECOND 100
#define SCR_WIDTH 640
#define SCR_HEIGHT 400

#include <stdint.h>
#include "linklist.h"

/* 定义fly_t链表 */
LINKLIST_DEF(fly)
	float x;
	int y;
	int text;
	float v;
LINKLIST_DEF_FI(fly)

typedef uint8_t bool;

#define true         1
#define false        0

/* 按键相关 */
void press_key(int scan_code);
void release_key(int ch);
bool query_key(int ch);
int last_key_code(void);
bool listen_keyboard();

/* 游戏逻辑相关 */
void create_new_letter(void);
void update_letter_pos(void);
bool update_keypress(void);

int get_hit(void);
int get_miss(void);
int get_fps(void);
void set_fps(int fps);
fly_t characters(void);

void init_sdl();
void redraw_screen(void);

#endif

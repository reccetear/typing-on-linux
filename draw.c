#include "draw.h"
#include "common.h"
#include "video.h"
#include <stdio.h>
#include <string.h>

static char *itoa(int a) {
	static char buf[30];
	snprintf(buf, 30, "%d", a);
	return buf;
}

void
redraw_screen() {
	fly_t it;
	const char *hit, *miss;

	prepare_buffer();
	/* 绘制每个字符 */
	for (it = characters(); it != NULL; it = it->_next) {
		static char buf[2];
		buf[0] = it->text + 'A'; buf[1] = 0;
		draw_string(buf, (int)(it->x), it->y, 15);
	}

	/* 绘制命中数、miss数、最后一次按键扫描码和fps */
	draw_string(itoa(last_key_code()), SCR_HEIGHT - 8, 0, 48);
	hit = itoa(get_hit());
	draw_string(hit, 0, SCR_WIDTH - strlen(hit) * 8, 10);
	miss = itoa(get_miss());
	draw_string(miss, SCR_HEIGHT - 8, SCR_WIDTH - strlen(miss) * 8, 12);
	draw_string(itoa(get_fps()), 0, 0, 14);
	draw_string("FPS", 0, strlen(itoa(get_fps())) * 8, 14);

	display_buffer(); /* 绘制缓冲区 */
}

static inline void draw_character(char ch, int x, int y, int color) {
	int i, j;
	char *p = font8x8_basic[(int)ch];
	for (i = 0; i < 8; i ++) 
		for (j = 0; j < 8; j ++) 
			if ((p[i] >> j) & 1)
				draw_pixel(x + i, y + j, color);
}

void draw_string(const char *str, int x, int y, int color) {
	while (*str) {
		draw_character(*str ++, x, y, color);
		if (y + 8 >= SCR_WIDTH) {
			x += 8; y = 0;
		} else {
			y += 8;
		}
	}
}

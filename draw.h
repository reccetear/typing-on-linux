#ifndef draw_h
#define draw_h

extern char font8x8_basic[128][8];

void draw_string(const char *str,int x,int y,int color);
static inline void draw_character(char ch,int x,int y,int color);
#endif

#ifndef video_h
#define video_h

typedef union {
	unsigned int val;
	struct { 
		unsigned char r, g, b, a;
	};
} Color;

void prepare_buffer();
void display_buffer();
void draw_pixel(int x,int y,char color);
#endif

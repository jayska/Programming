#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <shape.h>

typedef struct _Rectangle
{
	Shape shape;
	int height;
	int width;
} Rectangle;

void rectangle_init_full(Rectangle * rectangle, int x, int y, int width,
int height);

void rectangle_draw(Rectangle * self);

#endif /* __RECTANGLE_H_ */

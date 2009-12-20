#ifndef __LINE_H_
#define __LINE_H_

#include <shape.h>

typedef struct _Line
{
	Shape shape;
	int x2;
	int y2;
} Line;

void line_init_full(Line * line, int x, int y, int x2, int y2);

void line_draw(Line * self);

#endif /* __LINE_H_ */

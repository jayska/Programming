#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <object.h>

typedef struct _Shape
{
	Object object;
	int x;
	int y;
} Shape;

void shape_init_full(Shape * shape, int x, int y);

#endif /* __SHAPE_H_ */

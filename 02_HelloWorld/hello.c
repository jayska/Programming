#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <object.h>
#include <shape.h>
#include <rectangle.h>
#include <line.h>
#include <point.h>
#include <types.h>

int main()
{
	Rectangle * A;
	Line * B;
	Point * C;
	Shape * s;
	Object * o;
	int x, y;

	type_init();

	//A = rectangle_new(10,20, 100, 50);
	A = (Rectangle *) object_new(KLASS_ID_RECTANGLE);
	rectangle_draw(A);

	//B = line_new(10, 20, 20, 30);
	B = (Line *) object_new(KLASS_ID_LINE);
	line_draw(B);
	object_set(B, "x", 10, "y", 20, NULL);
//	object_get_properties(
//			B,
//			"x", & x,
//			NULL);
	
	o = object_new(KLASS_ID_POINT);
	if(object_is_a(o, KLASS_ID_SHAPE)) {
		s = (Shape *) o;
	}

	return 0;
}

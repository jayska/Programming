#include <rectangle.h>
#include <stdio.h>

void rectangle_init_full(
		Rectangle * rectangle,
		int x,
		int y,
		int width,
		int height)
{
	if(! rectangle) {
		return;
	}

	rectangle->height = height;
	rectangle->width = width;
}

void rectangle_init(Rectangle * rectangle)
{
	rectangle_init_full(rectangle, 0, 0, 0, 0);
}

static void rectangle_set_property(
		Object * object,
		const char * name,
		const struct _Value * value)
{

}

static void rectangle_get_property(
		Object * object,
		const char * name,
		struct _Value * value)
{

}

//Rectangle * rectangle_new(int x, int y, int width, int height)
//{
//	Rectangle * self = (Rectangle *) malloc(sizeof(Rectangle));
//	rectangle_init(self, x, y, width, height);
//
//	return self;
//}

void rectangle_draw(Rectangle * self)
{
	printf("Rectangle[x=%d, y=%d, width=%d, height=%d]\n",
			((Shape *) self)->x,
			((Shape *) self)->y,
			self->width,
			self->height);
}

void rectangle_class_init(Klass * klass)
{
	klass->id = KLASS_ID_RECTANGLE;
	klass->size = sizeof(Rectangle);
	klass->flags = 0;
	klass->parent_id = KLASS_ID_SHAPE;
	klass->object_init = (ObjectInitFunc) rectangle_init;
	klass->set_prop = rectangle_set_property;
	klass->get_prop = rectangle_get_property;
}

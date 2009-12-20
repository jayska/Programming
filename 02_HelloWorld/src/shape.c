#include <shape.h>

static void shape_set_property(
		Object * object,
		const char * name,
		const struct _Value * value)
{

}

static void shape_get_property(
		Object * object,
		const char * name,
		struct _Value * value)
{

}

void shape_init_full(Shape * shape, int x, int y)
{
	shape->x = x;
	shape->y = y;
}

void shape_init(Shape * shape)
{
	shape_init_full(shape, 0, 0);
}

void shape_class_init(Klass * klass)
{
	klass->id = KLASS_ID_SHAPE;
	klass->size = sizeof(Shape);
	klass->flags = KLASS_FLAG_ABSTRACT;
	klass->parent_id = KLASS_ID_OBJECT;
	klass->object_init = (ObjectInitFunc) shape_init;
	klass->set_prop = shape_set_property;
	klass->get_prop = shape_get_property;
}

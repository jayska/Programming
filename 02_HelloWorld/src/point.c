#include <point.h>

void point_init(Point * point)
{
}


static void point_set_property(
		Object * object,
		const char * name,
		const struct _Value * value)
{

}

static void point_get_property(
		Object * object,
		const char * name,
		struct _Value * value)
{

}

void point_class_init(Klass * klass)
{
	klass->id = KLASS_ID_POINT;
	klass->size = sizeof(Point);
	klass->flags = 0;
	klass->parent_id = KLASS_ID_SHAPE;
	klass->object_init = (ObjectInitFunc) point_init;
	klass->set_prop = point_set_property;
	klass->get_prop = point_get_property;
}

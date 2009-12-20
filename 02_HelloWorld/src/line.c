#include <line.h>
#include <stdio.h>

void line_init_full(Line * line, int x, int y, int x2, int y2)
{
	if (!line)	return;

	line->x2 = x2;
	line->y2 = y2;
}

void line_init(Line * line)
{
	line_init_full(line, 0, 0, 0, 0);
}

//Line * line_new(int x, int y, int x2, int y2)
//{
//	Line * self = (Line *) malloc(sizeof(Line));
//	line_init(self, x, y, x2, y2);
//
//	return self;
//}

void line_draw(Line * self)
{
	printf("Line x=%d, y=%d, x2=%d, y2=%d\n",
			((Shape *)self)->x,
			((Shape *)self)->y,
			self->x2,
			self->y2
	);
}

static void line_set_property(
		Object * object,
		const char * name,
		const struct _Value * value)
{

}

static void line_get_property(
		Object * object,
		const char * name,
		struct _Value * value)
{

}

void line_class_init(Klass * klass)
{
	klass->id = KLASS_ID_LINE;
	klass->size = sizeof(Line);
	klass->flags = 0;
	klass->parent_id = KLASS_ID_SHAPE;
	klass->object_init = (ObjectInitFunc) line_init;
	klass->set_prop = line_set_property;
	klass->get_prop = line_get_property;
}

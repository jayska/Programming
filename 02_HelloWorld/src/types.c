#include <types.h>
#include <object.h>
#include <stdio.h>

extern void object_class_init(Klass * klass);
extern void shape_class_init(Klass * klass);
extern void point_class_init(Klass * klass);
extern void line_class_init(Klass * klass);
extern void rectangle_class_init(Klass * klass);

Klass klasses[KLASS_ID_MAX] = {
		{ KLASS_ID_INVALID },
		{ KLASS_ID_BOOL, sizeof(bool), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_CHAR, sizeof(char), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_SHORT, sizeof(short), KLASS_FLAG_PRIMITIVE  },
		{ KLASS_ID_INT, sizeof(int), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_LONG, sizeof(long), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_FLOAT, sizeof(float), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_DOUBLE, sizeof(double), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_STRING, sizeof(char *), KLASS_FLAG_PRIMITIVE },
		{ KLASS_ID_POINTER, sizeof(void *), KLASS_FLAG_PRIMITIVE },
		{
				klass_init: object_class_init
		},
		{
				klass_init: shape_class_init,
		},
		{
				klass_init: rectangle_class_init
		},
		{
				klass_init: line_class_init
		},
		{
				klass_init: point_class_init
		},
};

void type_init()
{
	int i = 0;
	for(; i < KLASS_ID_MAX; i ++)
	{
		if (klasses[i].klass_init != NULL)
		{
			klasses[i].klass_init(& klasses[i]);
		}
	}
}

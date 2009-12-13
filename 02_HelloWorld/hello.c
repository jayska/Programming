#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define TRUE		(1)

#define FALSE		(1)

typedef int bool;

typedef enum
{
	KLASS_ID_INVALID = 0,
	KLASS_ID_OBJECT,
	KLASS_ID_SHAPE,
	KLASS_ID_RECTANGLE,
	KLASS_ID_LINE,
	KLASS_ID_POINT,
	KLASS_ID_MAX,
} KlassId;

typedef enum
{
	KLASS_FLAG_ABSTRACT	= 1 << 0,
} KlassFlag;

typedef struct _Klass Klass;

typedef void (* ObjectInitFunc)(void *);

struct _Klass
{
	KlassId id;

	int size;

	KlassFlag flags;

	KlassId parent_id;

	ObjectInitFunc init;
};

typedef struct _Object
{
	const Klass * klass;
} Object;

typedef struct _Shape
{
	Object object;
	int x;
	int y;
} Shape;

typedef struct _Point
{
	Shape shape;
} Point;

typedef struct _Rectangle
{
	Shape shape;
	int height;
	int width;
} Rectangle;

typedef struct _Line
{
	Shape shape;
	int x2;
	int y2;
} Line;

void shape_init_full(Shape * shape, int x, int y)
{
	shape->x = x;
	shape->y = y;
}

void shape_init(Shape * shape)
{
	shape_init_full(shape, 0, 0);
}

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

void point_init(Point * point)
{
}

const Klass klasses[KLASS_ID_MAX] = {
		{ KLASS_ID_INVALID },
		{ KLASS_ID_OBJECT, sizeof(Object), KLASS_FLAG_ABSTRACT, KLASS_ID_INVALID, NULL },
		{ KLASS_ID_SHAPE, sizeof(Shape), KLASS_FLAG_ABSTRACT, KLASS_ID_OBJECT, (ObjectInitFunc) shape_init },
		{ KLASS_ID_RECTANGLE, sizeof(Rectangle), 0, KLASS_ID_SHAPE, (ObjectInitFunc) rectangle_init},
		{ KLASS_ID_LINE, sizeof(Line), 0, KLASS_ID_SHAPE, (ObjectInitFunc) line_init },
		{ KLASS_ID_POINT, sizeof(Point), 0, KLASS_ID_SHAPE, (ObjectInitFunc) point_init },
};

void object_run_init(const Klass * klass, void * object)
{
	if(KLASS_ID_INVALID == klass->id) {
		return;
	}

	object_run_init(& klasses[klass->parent_id], object);
	if(klass->init) {
		klass->init(object);
	}
}

Object * object_new(KlassId id)
{
	const Klass * klass;
	Object * self;

	if(id <= KLASS_ID_INVALID || id >= KLASS_ID_MAX) {
		return NULL;
	}

	klass = & klasses[id];
	if(klass->flags & KLASS_FLAG_ABSTRACT) {
		fprintf(stderr, "Try to create an abstract object of type: %d\n", id);
		exit(1);
	}

	self = (Object *) malloc(klass->size);
	if(self) {
		object_run_init(klass, self);
		self->klass = klass;
	}

	return self;
}

bool object_is_a(Object * obj, KlassId id)
{
	const Klass * klass;

	if(! obj || ! id) {
		return FALSE;
	}

	klass = obj->klass;
	while(KLASS_ID_INVALID != klass->id) {
		if(klass->id == id) {
			return TRUE;
		}

		klass = & klasses[klass->parent_id];
	}

	return FALSE;
}

int main()
{
	Rectangle * A;
	Line * B;
	Point * C;
	Shape * s;
	Object * o;

	//A = rectangle_new(10,20, 100, 50);
	A = (Rectangle *) object_new(KLASS_ID_RECTANGLE);
	rectangle_draw(A);

	//B = line_new(10, 20, 20, 30);
	B = (Line *) object_new(KLASS_ID_LINE);
	line_draw(B);
	
	o = object_new(KLASS_ID_POINT);
	if(object_is_a(o, KLASS_ID_SHAPE)) {
		s = (Shape *) o;
	}

	return 0;
}

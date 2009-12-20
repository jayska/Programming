#include <object.h>
#include <stdlib.h>
#include <stdio.h>

extern const Klass klasses[KLASS_ID_MAX];

static void object_run_init(const Klass * klass, void * object)
{
	if(KLASS_ID_INVALID == klass->id) {
		return;
	}

	object_run_init(& klasses[klass->parent_id], object);
	if(klass->object_init) {
		klass->object_init(object);
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

void object_set(
		void * obj,
		const char * first_prop_name,
		...)
{
	va_list args;

	if(! obj || ! first_prop_name) {
		return;
	}

	va_start(args, first_prop_name);

	object_set_va_list(obj, first_prop_name, args);

	va_end(args);
}

void object_set_va_list(
		void * obj,
		const char * firest_prop_name,
		va_list args)
{

}

void object_class_init(Klass * klass)
{
	klass->id = KLASS_ID_OBJECT;
	klass->size = sizeof(Object);
	klass->flags = KLASS_FLAG_ABSTRACT;
	klass->parent_id = KLASS_ID_INVALID;
}

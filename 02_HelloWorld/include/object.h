#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <types.h>
#include <stdarg.h>

typedef enum
{
	KLASS_FLAG_ABSTRACT		= 1 << 0,

	KLASS_FLAG_PRIMITIVE	= 1 << 1,
} KlassFlag;

typedef struct _Klass Klass;

typedef struct _Object Object;

struct _Value;

typedef void (* ObjectKlassInitFunc)(Klass * klass);

typedef void (* ObjectInitFunc)(Object * object);

typedef void (* ObjectSetPropFunc)(
		Object * object,
		const char * name,
		const struct _Value * value);

typedef void (* ObjectGetPropFunc)(
		Object * object,
		const char * name,
		struct _Value * value);

struct _Klass
{
	KlassId id;

	int size;

	KlassFlag flags;

	KlassId parent_id;

	ObjectKlassInitFunc klass_init;

	ObjectInitFunc object_init;

	ObjectSetPropFunc set_prop;

	ObjectGetPropFunc get_prop;
};

struct _Object
{
	const Klass * klass;
};

Object * object_new(KlassId id);

bool object_is_a(Object * obj, KlassId id);

void object_set(
		void * obj,
		const char * firest_prop_name,
		...);

void object_set_va_list(
		void * obj,
		const char * firest_prop_name,
		va_list args);

#endif /* __OBJECT_H_ */

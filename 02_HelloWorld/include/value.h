#ifndef __VALUE_H_
#define __VALUE_H_

#include <object.h>

typedef struct _Value
{
	KlassId klass_id;

	union
	{
		bool bool_value;

		char char_value;

		short short_value;

		int int_value;

		long long_value;

		float float_value;

		double double_value;

		void * pointer_value;
	};
} Value;

void value_init(Value * self, KlassId klass_id);

KlassId vlaue_klass_id(Value * self);

bool value_get_bool(Value * self);

char value_get_char(Value * self);

short value_get_short(Value * self);

int value_get_int(Value * self);

long value_get_long(Value * self);

float value_get_float(Value * self);

double value_get_double(Value * self);

char * value_get_string(Value * self);

void * value_get_pointer(Value * self);

Object * value_get_object(Value * self);

void value_set_bool(Value * self, bool value);

void value_set_char(Value * self, char value);

void value_set_short(Value * self, short value);

void value_set_int(Value * self, int value);

void value_set_long(Value * self, long value);

void value_set_float(Value * self, float value);

void value_set_double(Value * self, double value);

void value_set_string(Value * self, const char * value);

void value_set_pointer(Value * self, void * value);

void value_set_object(Value * self, Object * value);

#endif /* __VALUE_H_ */

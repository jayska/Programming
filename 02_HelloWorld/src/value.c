#include <value.h>
#include <utils.h>
#include <string.h>
#include <stdlib.h>

void value_init(Value * self, KlassId klass_id)
{
	return_if_fail(self != NULL);

	self->klass_id = klass_id;
}

KlassId vlaue_klass_id(Value * self)
{
	return_val_if_fail(self != NULL, KLASS_ID_INVALID);

	return self->klass_id;
}

bool value_get_bool(Value * self)
{
	return_val_if_fail(self != NULL, FALSE);
	return_val_if_fail(self->klass_id == KLASS_ID_BOOL, FALSE);

	return self->bool_value;
}

char value_get_char(Value * self)
{
	return_val_if_fail(self != NULL, 0);
	return_val_if_fail(self->klass_id == KLASS_ID_CHAR, 0);

	return self->char_value;
}

short value_get_short(Value * self)
{
	return_val_if_fail(self != NULL, 0);
	return_val_if_fail(self->klass_id == KLASS_ID_SHORT, 0);

	return self->short_value;
}

int value_get_int(Value * self)
{
	return_val_if_fail(self != NULL, 0);
	return_val_if_fail(self->klass_id == KLASS_ID_INT, 0);

	return self->int_value;
}

long value_get_long(Value * self)
{
	return_val_if_fail(self != NULL, 0);
	return_val_if_fail(self->klass_id == KLASS_ID_LONG, 0);

	return self->long_value;
}

float value_get_float(Value * self)
{
	return_val_if_fail(self != NULL, 0.0);
	return_val_if_fail(self->klass_id == KLASS_ID_FLOAT, 0.0);

	return self->float_value;
}

double value_get_double(Value * self)
{
	return_val_if_fail(self != NULL, 0.0);
	return_val_if_fail(self->klass_id == KLASS_ID_DOUBLE, 0.0);

	return self->double_value;
}

char * value_get_string(Value * self)
{
	return_val_if_fail(self != NULL, NULL);
	return_val_if_fail(self->klass_id == KLASS_ID_STRING, NULL);

	if(self->long_value) {
		return strdup((char *) self->pointer_value);
	}

	return NULL;
}

void * value_get_pointer(Value * self)
{
	return_val_if_fail(self != NULL, NULL);
	return_val_if_fail(self->klass_id == KLASS_ID_POINTER, NULL);

	return self->pointer_value;
}

Object * value_get_object(Value * self)
{
	return_val_if_fail(self != NULL, NULL);
	return_val_if_fail(self->klass_id == KLASS_ID_OBJECT, NULL);

	return (Object *) self->pointer_value;
}

/* set */
void value_set_bool(Value * self, bool value)
{
	return_va_if_fail(self != NULL, FALSE);
	return_va_if_fail(self->klass_id == KLASS_ID_BOOL, FALSE);

	self->bool_value = (!value) ? FALSE : TRUE;
}

void value_set_char(Value * self, char value)
{
	return_va_if_fail(self != NULL, NULL);
	return_va_if_fail(self->klass_id == KLASS_ID_CHAR, NULL);

	self->char_value = value;
}

void value_set_short(Value * self, short value)
{
	return_va_if_fail(self != NULL, 0);
	return_va_if_fail(self->klass_id == KLASS_ID_SHORT, 0);

	self->short_value = value;
}

void value_set_int(Value * self, int value)
{
	return_va_if_fail(self != NULL, 0);
	return_va_if_fail(self->klass_id == KLASS_ID_INT, 0);

	self->int_value = value;
}

void value_set_long(Value * self, long value)
{
	return_va_if_fail(self != NULL, 0);
	return_va_if_fail(self->klass_id == KLASS_ID_LONG, 0);

	self->long_value = value;
}

void value_set_float(Value * self, float value)
{
	return_va_if_fail(self != NULL, 0.0);
	return_va_if_fail(self->klass_id == KLASS_ID_FLOAT, 0.0);

	self->float_value = value;
}

void value_set_double(Value * self, double value)
{
	return_va_if_fail(self != NULL, 0.0);
	return_va_if_fail(self->klass_id == KLASS_ID_DOUBLE, 0.0);

	self->double_value = value;
}

void value_set_string(Value * self, const char * value)
{
	return_va_if_fail(self != NULL, NULL);
	return_va_if_fail(self->klass_id == KLASS_ID_STRING, NULL);

	if (self->pointer_value) {
		free(self->pointer_value);
	}

	if (value)
		strdup(value);
	else
		self->pointer_value = NULL;
}

void value_set_pointer(Value * self, void * value)
{
	return_va_if_fail(self != NULL, NULL);
	return_va_if_fail(self->klass_id == KLASS_ID_POINTER, NULL);

	self->pointer_value = & value;
}

void value_set_object(Value * self, Object * value)
{
	return_va_if_fail(self != NULL, NULL);
	return_va_if_fail(self->klass_id == KLASS_ID_OBJECT, NULL);

	self->pointer_value = & value;
}

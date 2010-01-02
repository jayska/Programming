#include "myobj.h"

enum
{
	MYOBJ_PROP_MESSAGE = 1,
};

G_DEFINE_TYPE(MyObj, myobj, G_TYPE_OBJECT);

void myobj_hello_world_impl(MyObj * self)
{
	g_message("This is a MyObj: %s", self->message);
}

void myobj_hello_world(MyObj * self)
{
	MYOBJ_GET_CLASS(self)->hello_world(self);
}

void myobj_set_property(
		GObject        *object,
        guint           property_id,
        const GValue   *value,
        GParamSpec     *pspec)
{
	MyObj * self = MYOBJ(object);

	switch(property_id) {
	case MYOBJ_PROP_MESSAGE:
		myobj_set_message(self, g_value_get_string(value));
		break;
	}
}

void myobj_get_property(
		GObject        *object,
        guint           property_id,
        GValue   	   *value,
        GParamSpec     *pspec)
{
	MyObj * self = MYOBJ(object);

	switch(property_id) {
	case MYOBJ_PROP_MESSAGE:
		g_value_set_string(value, myobj_get_message(self));
		break;
	}
}

void myobj_class_init(MyObjClass * klass)
{
	GParamSpec * pspec;
	GObjectClass * gobject_class = G_OBJECT_CLASS(klass);

	gobject_class->set_property = myobj_set_property;
	gobject_class->get_property = myobj_get_property;
	klass->hello_world = myobj_hello_world_impl;

	pspec = g_param_spec_string(
			"message", "", "",
			NULL,
			G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT);
	g_object_class_install_property(
			gobject_class,
			MYOBJ_PROP_MESSAGE,
			pspec);
}

void myobj_init(MyObj * self)
{
	self->message = NULL;
}

const gchar * myobj_get_message(MyObj * self)
{
	return self->message;
}

void myobj_set_message(MyObj * self, const gchar * message)
{
	if(self->message) {
		g_free(self->message);
	}

	self->message = g_strdup(message);
}

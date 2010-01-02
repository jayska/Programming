#ifndef __MYOBJ_H_
#define __MYOBJ_H_

#include <glib-object.h>

#define TYPE_MYOBJ					(myobj_get_type())
#define MYOBJ(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MYOBJ, MyObj))
#define IS_MYOBJ(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MYOBJ))
#define MYOBJ_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MYOBJ, MyObjClass))
#define IS_MYOBJ_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MYOBJ))
#define MYOBJ_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MYOBJ, MyObjClass))

typedef struct _MyObjClass MyObjClass;

typedef struct _MyObj MyObj;

struct _MyObjClass
{
	GObjectClass parent;

	void (* hello_world)(MyObj * self);
};

struct _MyObj
{
	GObject parent;

	gchar * message;
};

GType myboj_get_type();

const gchar * myobj_get_message(MyObj * self);

void myobj_set_message(MyObj * self, const gchar * message);

#endif /* __MYOBJ_H_ */

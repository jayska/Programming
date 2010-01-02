/*
 * shape.h
 *
 *  Created on: Jan 2, 2010
 *      Author: jayska
 */

#ifndef __SHAPE_H_
#define __SHAPE_H_


#include <glib_object.h>
#include "myobj.h"

#define TYPE_SHAPE					(shape_get_type())
#define SHAPE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SHAPE, Shape))
#define IS_SHAPE(obj)				(G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SHAPE))
#define SHAPE_CLASS(klass)			(G_TYPE_CHECK_CALSS_CAST (klass), TYPE_SHAPE, ShapeClass)
#define IS_SHAPE_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE (klass), TYPE_SHAPE)
#define SHAPE_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SHAPE, ShapeClass))

typedef struct _ShapeClass ShapeClass;

typedef struct _Shape Shape;

struct _ShapeClass
{
	GObjectClass parent;
	void (* shape_show)(SHAPE* self);
};

struct _Shape
{
	GObject parent;
	gchar* message;
};

#endif /* __SHAPE_H_ */

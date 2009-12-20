#ifndef __CLASSES_H_
#define __CLASSES_H_

#ifndef NULL
#define NULL		(0)
#endif

#define TRUE		(1)

#define FALSE		(1)

typedef int bool;

typedef enum
{
	KLASS_ID_INVALID = 0,
	KLASS_ID_BOOL,
	KLASS_ID_CHAR,
	KLASS_ID_SHORT,
	KLASS_ID_INT,
	KLASS_ID_LONG,
	KLASS_ID_FLOAT,
	KLASS_ID_DOUBLE,
	KLASS_ID_STRING,
	KLASS_ID_POINTER,
	KLASS_ID_OBJECT,
	KLASS_ID_SHAPE,
	KLASS_ID_RECTANGLE,
	KLASS_ID_LINE,
	KLASS_ID_POINT,
	KLASS_ID_MAX,
} KlassId;

void type_init();

#endif /* __CLASSES_H_ */

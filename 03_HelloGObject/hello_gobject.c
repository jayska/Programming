#include "myobj.h"

int main()
{
	MyObj * myobj;

	g_type_init();

	myobj = MYOBJ(g_object_new(
			TYPE_MYOBJ,
			"message", "Bla Bla",
			NULL));
	myobj_hello_world(myobj);

	return 0;
}

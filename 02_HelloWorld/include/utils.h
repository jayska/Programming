#ifndef __UTILS_H_
#define __UTILS_H_

#include <stdio.h>

#define return_if_fail(expr) { \
	if(! (expr)) { \
		fprintf(stderr, "warning: %s", #expr); \
		return; \
	} \
}

#define return_val_if_fail(expr, retval) { \
	if(! (expr)) { \
		fprintf(stderr, "warning: %s", #expr); \
		return (retval); \
	} \
}

#endif /* __UTILS_H_ */

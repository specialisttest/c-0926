#ifndef _MY_SUPER_TEST_H_
#define _MY_SUPER_TEST_H_

#include <stdio.h>

#include "test.h"

void super_test() {
	test();
	puts("************");
	printf("Error. File %s Line %d Function %s\n", __FILE__, __LINE__, __func__);
	
}

#endif

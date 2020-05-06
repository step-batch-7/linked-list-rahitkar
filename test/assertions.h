#ifndef __ASSERTIONS_H
#define __ASSERTIONS_H

typedef char* Char_ptr;
typedef void* void_ptr;

void assert_null_equal(void_ptr expectedValue, void_ptr actualValue, Char_ptr message);
void assert_int_equal(int expectedValue, int actualValue, Char_ptr message);

#endif
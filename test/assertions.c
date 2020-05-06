#include <stdio.h>
#include <stdlib.h>

#include "assertions.h"

void assert_null_equal(void_ptr expectedValue, void_ptr actualValue, Char_ptr message)
{
  printf("%s\n", message);
  if (actualValue != expectedValue)
  {
    printf("✗ \n  -> expected: %s\n  -> actual: %s\n", (Char_ptr)expectedValue, (Char_ptr)actualValue);
    return;
  }
  printf("✓ \n  -> expected: %s\n  -> actual: %s\n", (Char_ptr)expectedValue, (Char_ptr)actualValue);
}

void assert_int_equal(int expectedValue, int actualValue, Char_ptr message)
{
  printf("%s\n", message);
  if (actualValue != expectedValue)
  {
    printf("✗ \n  -> expected: %d\n  -> actual: %d\n", expectedValue, actualValue);
    return;
  }
  printf("✓ \n  -> expected: %d\n  -> actual: %d\n", expectedValue, actualValue);
}
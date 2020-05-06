#include <stdio.h>
#include <stdlib.h>

#include "../list.h"

//________assert_functions__________
void assert_null_equal(void* expectedValue, void* actualValue, Char_ptr message)
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

// ________tests_______________
void test_create_list()
{
  printf("test_create_list\n");
  List_ptr list = create_list();
  assert_null_equal(NULL, list->head, "should create a empty list with null in head");
  assert_null_equal(NULL, list->last, "should create a empty list with null in last");
  assert_int_equal(0, list->count, "should create a empty list with 0 in count");
  printf("\n");
}

void test_create_node()
{
  printf("test_create_node\n");
  Node_ptr node = create_node(4);
  assert_int_equal(4, node->value, "should create a node with value 4");
  assert_null_equal(NULL, node->next, "should create a node with null next");
  printf("\n");
}

// _________runTest_________________
void runTest(void)
{
  test_create_list();
  test_create_node();
}

int main(void)
{
  runTest();
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "../list.h"

//________assert_functions__________
void assert_null_equal(void *expectedValue, void *actualValue, Char_ptr message)
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

void test_add_to_start()
{
  printf("test_add_to_start\n");
  List_ptr list = create_list();
  assert_int_equal(Success, add_to_start(list, 4), "should return Success status after adding 4 in a empty list");
  assert_int_equal(1, list->count, "count should incrise by 1");
  assert_int_equal(4, list->head->value, "list's head's value should be 4 for adding it in a empty list");
  assert_int_equal(4, list->last->value, "list's last's value should be 4 for adding it in a empty list");
  assert_null_equal(NULL, list->last->next, "list's last's next should be null");

  assert_int_equal(Success, add_to_start(list, 6), "should return Success status after adding 6 in the first position of the given list");
  assert_int_equal(2, list->count, "count should incrise by 1");
  assert_int_equal(6, list->head->value, "list's head's value should be 6 for adding it in the given list");
  assert_int_equal(4, list->last->value, "list's last's value should remain 4 after adding 6 in the first position of given list");
  printf("\n");
}

// _________runTest_________________
void runTest(void)
{
  test_create_list();
  test_create_node();
  test_add_to_start();
}

int main(void)
{
  runTest();
  return 0;
}
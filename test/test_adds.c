#include <stdio.h>
#include <stdlib.h>

#include "../list.h"
#include "assertions.h"
#include "test_adds.h"

void test_add_to_start()
{
  printf("test_add_to_start\n");
  List_ptr list = create_list();
  assert_int_equal(Success, add_to_start(list, 4), "should return Success status after adding 4 in a empty list");
  assert_int_equal(1, list->count, "count should increase by 1");
  assert_int_equal(4, list->head->value, "list's head's value should be 4 for adding it in a empty list");
  assert_int_equal(4, list->last->value, "list's last's value should be 4 for adding it in a empty list");
  assert_null_equal(NULL, list->last->next, "list's last's next should be null");

  assert_int_equal(Success, add_to_start(list, 6), "should return Success status after adding 6 in the first position of the given list");
  assert_int_equal(2, list->count, "count should increase by 1");
  assert_int_equal(6, list->head->value, "list's head's value should be 6 for adding it in the given list");
  assert_int_equal(4, list->last->value, "list's last's value should remain 4 after adding 6 in the first position of given list");
  printf("\n");
}

void test_add_to_end()
{
  printf("test_add_to_end\n");
  List_ptr list = create_list();
  assert_int_equal(Success, add_to_end(list, 4), "should return Success status after adding 4 in a empty list");
  assert_int_equal(1, list->count, "count should increase by 1");
  assert_int_equal(4, list->head->value, "list's head's value should be 4 for adding it in a empty list");
  assert_int_equal(4, list->last->value, "list's last's value should be 4 for adding it in a empty list");
  assert_null_equal(NULL, list->last->next, "list's last's next should be null");

  assert_int_equal(Success, add_to_end(list, 6), "should return Success status after adding 6 in the last position of the given list");
  assert_int_equal(2, list->count, "count should increase by 1");
  assert_int_equal(6, list->last->value, "list's last's value should be 6 for adding it in the given list");
  assert_int_equal(4, list->head->value, "list's head's value should remain 4 after adding 6 in the last position of given list");
  printf("\n");
}
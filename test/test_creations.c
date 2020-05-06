#include <stdio.h>
#include <stdlib.h>

#include "../list.h"
#include "assertions.h"
#include "test_creations.h"

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
#include <stdio.h>
#include <stdlib.h>

#include "../list.h"

void show_result(int status, char *message)
{
  printf("%s", message);
  if (status)
  {
    printf("PASSED\n");
    return;
  }
  printf("FAILED\n");
}

void test_create_node(int value, char* message)
{
  Node_ptr node = create_node(value);
  if (node->value == value && node->next == NULL)
  {
    show_result(1, message);
    return;
  }
  show_result(0, message);
}

void test_create_list(char* message)
{
  List_ptr list = create_list();
  if (list->count == 0 && list->head == NULL && list->last == NULL)
  {
    show_result(1, message);
    return;
  }
  show_result(0, message);
}

void test_add_to_start(List_ptr list, int value, Char_ptr message)
{
  int previous_count = list->count;
  add_to_start(list, value);
  if (list->count == previous_count + 1 && list->head->value == value)
  {
    show_result(1, message);
    return;
  }
  show_result(0, message);
}

void test_add_to_end(List_ptr list, int value, Char_ptr message)
{
  int previous_count = list->count;
  add_to_end(list, value);
  if (list->count == previous_count + 1 && list->last->value == value)
  {
    show_result(1, message);
    return;
  }
  show_result(0, message);
}

int main(void)
{
  test_create_list("should create a empty list\n");
  printf("\n");

  test_create_node(4, "should create a node with value 4\n");
  printf("\n");

  printf("add_to_start\n");
  List_ptr list = create_list();
  display(list);
  test_add_to_start(list, 2, "should insert value 2 in possition 0 in a empty list\n");
  test_add_to_start(list, 4, "should enter value 4 in possition 0\n");
  printf("\n");

  printf("add_to_end\n");
  list = create_list();
  test_add_to_end(list, 4, "should insert value 2 in possition 0 in a empty list\n");
  test_add_to_end(list, 6, "should enter value 3 in possition 1\n");
}
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

int main(void)
{
  test_create_list("should create a empty list\n");
  printf("\n");
  test_create_node(4, "should create a node with value 4\n");
}
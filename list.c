#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  if (list == NULL)
  {
    printf("Memory is not available");
    exit(1);
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Memory is not available");
    exit(1);
  }
  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  if (list == NULL)
  {
    return Failure;
  }
  
  Node_ptr new_node = create_node(value);

  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  Node_ptr p_walk = list->head;
  Node_ptr temp_node = list->head;
  if (list->count <= position)
  {
    return Failure;
  }
  
  if (position == 0)
  {
    list->head = p_walk->next;
  }
  int counter = 0;
  while (counter < position)
  {
    temp_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  temp_node->next = p_walk->next;
  list->count--;
  free(p_walk);
  return Success;
}

void display(List_ptr list)
{
  Node_ptr iterator = list->head;
  while (iterator != NULL)
  {
    printf("%d ", iterator->value);
    iterator = iterator->next;
  }
  printf("\n");
}

void destroy_list(List_ptr list)
{
  Node_ptr iterator = list->head;
  Node_ptr temp;

  while (iterator != NULL)
  {
    temp = iterator;
    iterator = iterator->next;
    free(temp);
  }
  free(list);
}
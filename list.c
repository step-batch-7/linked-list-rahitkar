#include "stdlib.h"
#include <stdio.h>

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

Status insert_at(List_ptr list, int value, int position)
{
  if (list == NULL || list->count < position)
  {
    return Failure;
  }
  Node_ptr p_walk = list->head;
  Node_ptr previous_node = list->head;
  if (position == 0)
  {
    list->head = create_node(value);
    list->head->next = p_walk;
    list->count++;
    return Success;
  }
  int counter = 0;
  while (counter != position)
  {
    previous_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  Node_ptr new_node = create_node(value);
  previous_node->next = new_node;
  new_node->next = p_walk;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  return insert_at(list, value, 0);
}

Status add_to_end(List_ptr list, int value)
{
  return insert_at(list, value, list->count);
}

Status add_unique(List_ptr list, int value)
{
  if (list == NULL || list->head == NULL)
  {
    return Failure;
  }
  int position = search(list,value);
  if (position >= list->count)
  {
    return add_to_end(list, value);
  }
  return Failure;
}

Status remove_at(List_ptr list, int position)
{
  if (list == NULL || list->count <= position)
  {
    return Failure;
  }

  Node_ptr p_walk = list->head;
  Node_ptr temp_node = list->head;

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

Status remove_from_start(List_ptr list)
{
  return remove_at(list, 0);
}

Status remove_from_end(List_ptr list)
{
  return remove_at(list, (list->count) - 1);
}

int search(List_ptr list, int value)
{
  int position = 0;
  Node_ptr iterator = list->head;
  while (iterator != NULL)
  {
    if (iterator->value == value)
    {
      return position;
    }
    position++;
    iterator = iterator->next;
  }
  return position;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  if (list == NULL || list->head == NULL)
  {
    return Failure;
  }
  int position = search(list, value);
  if (position < list->count)
  {
    remove_at(list, position);
    return Success;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  int status = remove_first_occurrence(list, value), counter = 0;
  while(status == 1)
  {
  status = remove_first_occurrence(list, value);
  counter++;
  }
  return counter > 0 ? Success : Failure;
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

Status clear_list(List_ptr list)
{
  if (list == NULL)
  {
    return Failure;
  }
  while (list->head != NULL)
  {
  remove_from_start(list);
  }
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}
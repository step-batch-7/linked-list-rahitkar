#include <stdio.h>
#include <stdlib.h>

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
  if (list == NULL || list->count < position || position < 0)
  {
    return Failure;
  }

  if (position == 0)
  {
    return add_to_start(list, value);
  }

  Node_ptr p_walk = list->head;
  Node_ptr previous_node = list->head;
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
  Node_ptr previous_head = list->head;
  if (list == NULL)
  {
    return Failure;
  }
  if (list->head == NULL)
  {
    list->head = create_node(value);
    list->last = list->head;
    list->count++;
    return Success;
  }
  list->head = create_node(value);
  list->head->next = previous_head;
  list->count++;
  return Success;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr previous_last = list->last;
  if (list == NULL)
  {
    return Failure;
  } 
  if (list->head == NULL)
  {
    return add_to_start(list, value);
  }
  list->last = create_node(value);
  previous_last->next = list->last;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  if (list == NULL || list->head == NULL)
  {
    return Failure;
  }
  int position = search(list, value);
  if (position >= list->count)
  {
    return add_to_end(list, value);
  }
  return Failure;
}

Status remove_at(List_ptr list, int position)
{
  if (list == NULL || list->count <= position || position < 0) 
  {
    return Failure;
  }

  if (position == 0)
  {
    return remove_from_start(list);
  }

  if (list->count -1 == position)
  {
    return remove_from_end(list);
  }
  
  int counter = 0;
  Node_ptr p_walk = list->head;
  Node_ptr temp_node = list->head;
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
  if (list == NULL || list->head == NULL)
  {
    return Failure;
  }
  Node_ptr previous_head = list->head;
  list->head = list->head->next;
  list->count--;
  free(previous_head);
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list == NULL || list->last == NULL)
  {
    return Failure;
  }
  
  if (list->count == 1)
  {
    return remove_from_start(list);
  }
  
  int counter = 0;
  Node_ptr p_walk = list->head;
  Node_ptr temp_node = list->head;
  list->count--;
  while (counter < list->count)
  {
    temp_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  list->last = temp_node;
  list->last->next = NULL;
  free(p_walk);
  return Success;
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
  while (status == 1)
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
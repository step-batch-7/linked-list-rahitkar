#include "list.h"

List_ptr create_list(void)
{
  List *list = malloc(sizeof(List));
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

Node *create_node(int value)
{
  Node *new_node = malloc(sizeof(Node));
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
  
  Node *new_node = create_node(value);

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

void display(List_ptr list)
{
  Node* iterator = list->head;
  while (iterator != NULL)
  {
    printf("%d ", iterator->value);
    iterator = iterator->next;
  }
  printf("\n");
}

void destroy_list(List_ptr list)
{
  Node *iterator = list->head;
  Node *temp;

  while (iterator != NULL)
  {
    temp = iterator;
    iterator = iterator->next;
    free(temp);
  }
  free(list);
}
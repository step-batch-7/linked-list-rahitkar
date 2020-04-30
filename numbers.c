#include <stdio.h>
#include "list.h"

void show_menu()
{
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform ");
}

void show_result(Status result, Char_ptr message)
{
  if (result)
  {
    printf("number %s\n", message);
    return;
  }
  printf("number not %s\n", message);
  return;
}

void oparate_on(List_ptr list, char option)
{
  Status result;
  int value, position;
  switch (option)
  {
  case 'a':
    printf("enter your number ");
    scanf("%d", &value);
    result = add_to_end(list, value);
    show_result(result, "added");
    break;

    case 'b':
    printf("enter your number ");
    scanf("%d", &value);
    result = add_to_start(list, value);
    show_result(result, "added");
    break;

    case 'c':
    printf("enter your number ");
    scanf("%d", &value);
    printf("enter position ");
    scanf("%d", &position);
    result = insert_at(list, value, position);
    show_result(result, "added");
    break;

    case 'd':
    printf("enter your number ");
    scanf("%d", &value);
    result = add_unique(list, value);
    show_result(result, "added");
    break;

    case 'e':
    result = remove_from_start(list);
    show_result(result, "removed");
    break;

    case 'f':
    result = remove_from_end(list);
    show_result(result, "removed");
    break;

    case 'g':
    printf("enter position ");
    scanf("%d", &position);
    result = remove_at(list, position);
    show_result(result, "removed");
    break;

    case 'h':
    printf("enter number ");
    scanf("%d", &value);
    result = remove_first_occurrence(list, value);
    show_result(result, "removed");
    break;

    case 'i':
    printf("enter number ");
    scanf("%d", &value);
    result = remove_all_occurrences(list, value);
    show_result(result, "removed");
    break;

    case 'j':
    result = clear_list(list);
    show_result(result, "cleared");
    break;

    case 'k':
    printf("enter number ");
    scanf("%d", &value);
    result = search(list, value) < list->count ? 1 : 0;
    show_result(result, "exits");
    break;

    case 'l':
    display(list);
    break;

  default:
    printf("option not listed\n");
    break;
  }
}

int main(void)
{
  char option;
  List_ptr list = create_list();
  while (option != 'm')
  {
    show_menu();
    scanf(" %c", &option);
    oparate_on(list, option);
  }
  destroy_list(list);
  return 0;
}
#include "test_creations.h"
#include "test_adds.h"

int main(void)
{
  test_create_list();
  test_create_node();
  test_add_to_start();
  test_add_to_end();
  test_insert_at();
  return 0;
}
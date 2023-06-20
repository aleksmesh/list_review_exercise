#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

int main() {
  list_t user_list = {0};
  insert_next_to_list(&user_list, 3);
  insert_next_to_list(&user_list, 4);
  printf("list.data = %d list.next = %p\n", user_list.data, user_list.next);
  printf("list.data = %d list.next = %p\n", user_list.next->data, user_list.next->next);
  printf("list.next.data = %d list.next.next = %p\n", user_list.next->next->data, user_list.next->next->next);
//  printf("list data = %s\n", item_data(user_list.next, NULL));
  return EXIT_SUCCESS;
}

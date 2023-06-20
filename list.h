typedef struct list_s
{
        struct list_s *next; /* NULL for the last item in a list */
        int data;
}
list_t;

/* Counts the number of items in a list.
 */
int count_list_items(const list_t *head) {
  // FIXME Absent check NULL != head
  //      if (NULL == head) {
  //        return 0;
  //      }
  if (head->next) {
    // Recursive call is slower than while loop and can cause a stack overflow
    return count_list_items(head->next) + 1;
  } else {
    return 1;
  }
}

/* TODO Variant with loop
int count_list_items(const list_t* head) {
  list_t* item = head;
  int count = 0;
  while (NULL != item) {
    item = item->next;
    ++count;
  }
  return count;
}
*/

/* Inserts a new list item after the one specified as the argument.
 */
// FIXME It's better to change the return value type to list_t*
//      and return a pointer to the created element or NULL if
//      something is wrong.
void insert_next_to_list(list_t *item, int data) {
  // FIXME Hard to understand code with wrong assignment.
  //      It is better to break instructions into several lines of code.
  //      Absent check NULL == item
  //      Absent check NULL == malloc
  //      newitem->next = newitem
  (item->next = malloc(sizeof(list_t)))->next = item->next;
  item->next->data = data;
}

/* TODO Variant with returning created item
list_t* insert_next_to_list(list_t* item, int data) {
  list_t* next = malloc(sizeof(list_t));
  if (NULL == next) {
    return NULL;
  }
  next->data = data;
  next->next = NULL;
  if (NULL != item) {
    next->next = item->next;
    item->next = next;
  }
  return next;
}*/

/* Removes an item following the one specificed as the argument.
 */
// FIXME It's better to change the return value to list_t*
//      and return value of item->next->next or NULL
void remove_next_from_list(list_t* item) {
  // FIXME Absent check NULL == item
  if (item->next) {
    free(item->next);
    // FIXME Access to item->next->next after free item->next!
    item->next = item->next->next;
  }
}

/* TODO Variant with list_t* returning value
list_t* remove_next_from_list(list_t* item) {
  if (NULL == item) {
    return NULL;
  }
  if (NULL == item->next) {
    return NULL;
  }
  list_t* next = item->next;
  item->next = item->next->next;
  free(next);
  return item->next;
}*/

/* Returns item data as text.
 */
char* item_data(const list_t* list) {
  char buf[12];

  // FIXME Absent check NULL != list
  //       snprintf is safer choice
  sprintf(buf, "%d", list->data);
  // FIXME return pointer to variable on stack. 
  //       Accessing data at this address outside of this
  //       function can lead undefined behavior.
  return buf;
}

/* TODO Variant with second parameter char* data
char* item_data(const list_t* list, char* data) {
  if (NULL == list) {
    return NULL;
  }
  char* buf = data;
  if (NULL == buf) {
    buf = malloc(12);
  }
  if (NULL == buf) {
    return NULL;
  }
  snprintf(buf, 12, "%d", list->data);
  return buf;
}*/


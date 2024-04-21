#ifndef MYLIST_H
#define MYSLIST_H
typedef struct mylist mylist;
mylist* create();
mylist* create_copy(mylist* a);
mylist* add_after(mylist* a, int x);
mylist* add_before(mylist* a, int x);
mylist* del_cur(mylist* a);
mylist* go_next(mylist* a);
mylist* go_prev(mylist* a);
int ret_cur(mylist* a);
void say_all(mylist* a);
void list_free(mylist* a);
#endif // MYLIST_H

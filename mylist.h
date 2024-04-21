#ifndef MYLIST_H
#define MYSLIST_H
typedef struct mylist mylist;
mylist* create();
mylist* create_copy(mylist* a);
void add_after(mylist* a, int x);
void add_before(mylist* a, int x);
void del_cur(mylist* a);
void go_next(mylist* a);
void go_prev(mylist* a);
int ret_cur(mylist* a);
void say_all(mylist* a);
void list_free(mylist* a);
#endif // MYLIST_H

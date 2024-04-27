#include "mylist.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
struct mylist
{
    mylist* prev;
    mylist* next;
    int num;
    int isel;
};
mylist* create()
{
    mylist* a=malloc(sizeof(mylist));
    if(!a)
    {
        return NULL;
    }
    a->next=a;
    a->prev=a;
    a->isel=0;
    return a;
}
mylist* create_copy(mylist* a)
{
    mylist* b=malloc(sizeof(mylist));
    mylist* st=b;
    b->num=a->num;
    b->isel=a->isel;
    mylist* d=a;
    d=a->next;
    while(d!=a)
    {
        mylist* e=malloc(sizeof(mylist));
        e->num=d->num;
        e->isel=d->isel;
        b->next=e;
        e->prev=b;
        b=e;
        d=d->next;
    }
    b->next=st;
    st->prev=b;
    return st;
}
mylist* add_after(mylist* a, int x)
{
    mylist* b=malloc(sizeof(mylist));
    b->num=x;
    b->isel=1;
    b->prev=a;
    b->next=a->next;
    a->next->prev=b;
    a->next=b;
    if(!a->isel)
    {
        a=a->next;

    }
    return a;
}
mylist* add_before(mylist* a, int x)
{
    mylist* b=malloc(sizeof(mylist));
    b->num=x;
    b->isel=1;
    b->next=a;
    b->prev=a->prev;
    a->prev->next=b;
    a->prev=b;
    if(!a->isel)
    {
        a=a->prev;
    }
    return a;
}
mylist* del_cur(mylist* a)
{
    if(a->isel==0)
    {
        return a;
    }
    a->prev->next=a->next;
    a->next->prev=a->prev;
    mylist* b=a;
    a=a->next;
    free(b);
    if(!a->isel)
    {
        a=a->next;
    }
    return a;
}
mylist* go_next(mylist* a)
{
    a=a->next;
    if(!a->isel)
    {
        a=a->next;
    }
    return a;
}
mylist* go_prev(mylist* a)
{
    a=a->prev;
    if(!a->isel)
    {
        a=a->prev;
    }
    return a;
}
int ret_cur(mylist* a)
{
    return a->num;
}
void say_all(mylist* a)
{
    mylist* b=a;
    mylist* st=b;
    if(b->isel)
    {
        printf("%d ", b->num);
    }
    b=b->next;
    while(b!=st)
    {
        if(b->isel)
        {
            printf("%d ", b->num);
        }
        b=b->next;
    }
    printf("\n");
}
void list_free(mylist* a)
{
    while(a->next!=a)
    {
        del_cur(a->next);
    }
    del_cur(a);
}

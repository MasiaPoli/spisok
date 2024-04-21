#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"
int main()
{
    mylist* a[100];
    int n=0;
    while(1)
    {
        printf("If you want to create an empty list, write 0\n, if you want to create a copy, write 1 and the origin's number\n");
        printf("If you want to add after, write 2, number of list and element\n, If you want to add before, write 3, number of list and element\n");
        printf("If you want to delete current, write 4 and number of list\n, If you want to see, write 5 and number of list\n, if you want to go next, write 6 and number of list\n, if you want to go back, write 7  and number of list\n,  if you want to exit, write 8\n");
        int c;
        scanf("%d", &c);
         int k, x;
        switch(c)
        {
        case 0:
            a[n]=create();
            n++;
            break;
        case 1:
            scanf("%d", &k);
            a[n]=create_copy(a[k]);
            n++;
            break;
        case 2:
            scanf("%d%d", &k, &x);
            a[k]=add_after(a[k], x);
            break;
        case 3:
            scanf("%d%d", &k, &x);
           a[k]= add_before(a[k], x);
            break;
        case 4:
            scanf("%d", &k);
            a[k]=del_cur(a[k]);
            break;
        case 5:
            scanf("%d", &k);
            say_all(a[k]);
            break;
        case 6:
            scanf("%d", &k);
            a[k]=go_next(a[k]);
            break;
        case 7:
            scanf("%d", &k);
            a[k]=go_prev(a[k]);
            break;
        case 8:
            for(int i=0; i<n; i++)
            {
                list_free(a[i]);
            }
            return 0;
        }
    }
    return 0;
}

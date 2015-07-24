#include <iostream>
#include <cstdio>

using namespace std;

struct list {
    list *prev;
    int data;
    list *next;
};

list *insertList(int n, list *listTail) {
    list *n_list = new list;
    n_list->next = listTail->next;
    n_list->data = n;
    n_list->prev = listTail;
    listTail->next->prev = n_list;
    listTail->next = n_list;
    return n_list;
}

list *runLeft(int *n, list *listTail) {
    //printf("runLeft n = %d ",*n);
    for (int i = 0; i < *n-1; ++i) {
        listTail = listTail->prev;
    }
    listTail->prev->next = listTail->next;
    listTail->next->prev = listTail->prev;
    printf("%d\n",listTail->data);
    list *listTmp = listTail;
    listTail = listTail->next;
    delete listTmp;
    return listTail;
}

list *runRight(int *n, list *listTail) {
    //printf("runRight n = %d ",*n);
    for (int i = 0; i < *n-1; ++i) {
        listTail = listTail->next;
    }
    listTail->prev->next = listTail->next;
    listTail->next->prev = listTail->prev;
    printf("%d\n",listTail->data);
    list *listTmp = listTail;
    listTail = listTail->next;
    delete listTmp;
    return listTail;
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int remain = n;
    list *circle = new list;
    circle->next = circle;
    circle->prev = circle;
    circle->data = 1;
    list *listTail = circle;
    for (int i = 2; i <= n; ++i) {
        listTail = insertList(i, listTail);
    }
    listTail = circle;
    while (remain > 1) {
        //printf("test\n");
        if (k < remain) {
            //printf("in if\n");
            if (remain-k+2 >= k) {
                listTail = runRight(&k, listTail);
            }
            else {
                int tmp = remain-k+2;
                listTail = runLeft(&tmp, listTail);
            }
        }
        else if (k > remain) {
            //printf("in else\n");
            int tmp;
            if (k%remain == 0) {
                tmp = remain;
            }
            else tmp = k%remain;
            if (remain-k+2 >= k) {
                listTail = runRight(&tmp, listTail);
            }
            else {
                int tmp2 = remain-tmp+2;
                listTail = runLeft(&tmp2, listTail);
            }
        }
        else {
            listTail = listTail->prev;
            //k = listTail->data;
            list *listTmp = listTail;
            listTail->next->prev = listTail->prev;
            listTail->prev->next = listTail->next;
            printf("%d\n",listTail->data);
            listTail = listTail->next;
            delete listTmp;
        }
        --remain;
    }
    printf("%d\n",listTail->data);
}
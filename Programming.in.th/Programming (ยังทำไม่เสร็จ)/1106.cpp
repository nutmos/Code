#include <iostream>
#include <cstdio>

using namespace std;

struct list {
    list *prev;
    int data;
    list *next;
};

void printList(list *listTail) {
    printf("printList\n");
    printf("%d prev = %d next = %d\n",listTail->data,listTail->prev->data,listTail->next->data);
    list *ptr = listTail->next;
    while (ptr != listTail) {
        printf("%d prev = %d next = %d\n",ptr->data,ptr->prev->data,ptr->next->data);
        ptr = ptr->next;
    }
    printf("end list\n");
}

void printReverse(list *listTail) {
    printf("printReverse\n");
    printf("%d prev = %d next = %d\n",listTail->data,listTail->prev->data,listTail->next->data);
    list *ptr = listTail->prev;
    while (ptr != listTail) {
        printf("%d prev = %d next = %d\n",ptr->data,ptr->prev->data,ptr->next->data);
        ptr = ptr->prev;
    }
    printf("end list\n");
}

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
    for (int i = 0; i < *n-1; ++i) {
        listTail = listTail->prev;
    }
    *n = listTail->data;
    listTail->prev->next = listTail->next;
    listTail->next->prev = listTail->prev;
    list *listTmp = listTail;
    listTail = listTail->next;
    delete listTmp;
    return listTail;
}

list *runRight(int *n, list *listTail) {
    for (int i = 0; i < *n-1; ++i) {
        listTail = listTail->next;
    }
    *n = listTail->data;
    listTail->prev->next = listTail->next;
    listTail->next->prev = listTail->prev;
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
    list *begin = NULL;
    for (int i = 2; i <= n; ++i) {
        listTail = insertList(i, listTail);
        if (i == k) begin = listTail;
    }
    listTail = begin;
    --remain;
    listTail->prev->next = listTail->next;
    listTail->next->prev = listTail->prev;
    list *listTmp = listTail;
    listTail = listTail->next;
    delete listTmp;
    while (remain > 1) {
        if (k < remain) {
            if (remain-k+2 >= k) {
                listTail = runRight(&k, listTail);
            }
            else {
                k = remain-k+2;
                listTail = runLeft(&k, listTail);
            }
        }
        else if (k > remain) {
            if (k%remain == 0) {
                k = remain;
            }
            else k = k%remain;
            if (remain-k+2 >= k) {
                listTail = runRight(&k, listTail);
            }
            else {
                k = remain-k+2;
                listTail = runLeft(&k, listTail);
            }
        }
        else {
            listTail = listTail->prev;
            k = listTail->data;
            list *listTmp = listTail;
            listTail->next->prev = listTail->prev;
            listTail->prev->next = listTail->next;
            listTail = listTail->next;
            delete listTmp;
        }
        --remain;
    }
    printf("%d",listTail->data);
}
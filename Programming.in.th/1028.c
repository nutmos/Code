#include <iostream>
#include <stdlib.h>

using namespace std;

int operation(char, int, int);
int print(int);

typedef struct _list {
    int *key_num;
    char *key_ch;
    struct _list *prev;
    struct _list *next;
}list;

list *list_alloc() {
    return (list *)malloc(sizeof(list));
}

list *find_list(char key_ch, list *head) {
    list *x = head->next;
    while (x != NULL) {
        if (*(x->key_ch) == key_ch) {
            //printf("found %c %d @ %d\n",*(x->key_ch),*(x->key_num),x);
            return x;
        }
        x = x->next;
    }
}

int find_number_in_list(char key_ch, list *head) {
    list *x = head->next;
    while (x != NULL) {
        if (*(x->key_ch) == key_ch) {
            //printf("found %c %d @ %d\n",*(x->key_ch),*(x->key_num),x);
            return *(x->key_num);
        }
        x = x->next;
    }
}

list *insert_list(char key_ch, int key_num, list *head) {
    list *x = list_alloc();
    x->key_ch = (char *)malloc(sizeof(char));
    *(x->key_ch) = key_ch;
    x->key_num = (int *)malloc(sizeof(int));
    *(x->key_num) = key_num;
    x->next = head->next;
    x->prev = head;
    head->next = x;
    if (head->next != NULL) head->next->prev = x;
}

list *print_list(list *head) {
    list *x = head->next;
    while (x != NULL) {
        //printf("variable is %c value is %d",*(x->key_ch),*(x->key_num));
        x = x->next;
    }
}

int main() {
    char ch = 0;
    list *head = list_alloc();
    head->key_ch = NULL;
    head->key_num = NULL;
    head->next = NULL;
    head->prev = NULL;
    int count = 0;
    int array[100];
    list *wait_print = list_alloc();
    wait_print->key_ch = NULL;
    wait_print->key_num = NULL;
    wait_print->next = NULL;
    wait_print->prev = NULL;
    while (ch != '!') {
        int num;
        char variable,ch2;
        cin >> ch;
        if (ch == '=') {
            cin >> variable >> num;
            insert_list(variable, num, head);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            cin >> variable >> ch2;
            list *ptr_variable = find_list(variable, head);
            //printf("variable is %d\n",*(ptr_variable->key_num));
            //printf("%c",ch2);
            list *ptr_ch2 = find_list(ch2, head);
            //printf("ch2 is %d\n",*(ptr_ch2->key_num));
            *(ptr_variable->key_num) = operation(ch, *(ptr_variable->key_num), *(ptr_ch2->key_num));
        }
        else if (ch == '#') {
            cin >> variable;
            int num = find_number_in_list(variable, head);
            //printf("%d",num);
            array[count] = num;
            //printf("%d\n",array[count]);
            count++;
        }
        
        //printf("%c %c\n",ch,variable);
    }
    for (int i = 0; i < count; i++) {
        printf("%d\n",array[i]);
    }
    printf("!");
    return 0;
}

int operation(char signal, int a, int b) {
    if (signal == '+') {
        return a+b;
    }
    else if (signal == '-') {
        return a-b;
    }
    else if (signal == '*') {
        return a*b;
    }
    else if (signal == '/') {
        return a/b;
    }
}

int print(int num) {
    return num;
}
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

typedef struct _list {
    unsigned int *key;
    struct _list *next;
    struct _list *prev;
}list;

list *list_alloc() {
    return (list*)malloc(sizeof(list));
}

list *insert_front(int key, list* head) {
    list *x = list_alloc();
    x->key = (unsigned int*)malloc(sizeof(unsigned int));
    *(x->key) = key;
    x->prev = head;
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    if (head->prev == head) {
        head->prev = x;
    }
    return x;
}

list *insert_in_list(int key, list* insert_after_this, list* head) {
    list *x = list_alloc();
    x->key = (unsigned int *)malloc(sizeof(int));
    *(x->key) = key;
    x->prev = insert_after_this;
    x->next = insert_after_this->next;
    insert_after_this->next->prev = x;
    insert_after_this->next = x;
    return x;
}

list *remove_front(list* head) {
    list *x = head->next;
    x->next->prev = head;
    head = x->next;
    return x;
}

list *print_list(list *head) {
    list *x = head->next;
    while (x != head) {
        if (*(x->key) == UINT_MAX) {
            cout << "x->key @ " << x << " is "<< "-1" << '\n';
            x = x->next;
            continue;
        }
        cout << "x->key @ " << x << " is " << *(x->key) << '\n';
        x = x->next;
    }
    return x;
    //cout << '\n';
}

list *delete_front(list *head) {
    list *x = NULL;
    head->next->prev = head;
    head->next = head->next->next;
    return x;
}

list *print_reverse(list *head) {
    list *x = head->prev;
    while (x != head) {
        if (*(x->key) == UINT_MAX) {
            cout << "-1\n";
            x = x->prev;
            continue;
        }
        cout << *(x->key) << '\n';
        x = x->prev;
    }
    return x;
}

int main() {
    int n;
    char ch;
    unsigned int input;
    cin >> n;
    
    list *input_list = list_alloc();
    input_list->key = NULL;
    input_list->prev = input_list;
    input_list->next = input_list;
    
    //cout << "input_list head is @ " << input_list << '\n';
    
    list *goods_list = list_alloc();
    goods_list->key = NULL;
    goods_list->next = goods_list;
    goods_list->prev = goods_list;
    
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (ch == 'P') {
            cin >> input;
            //cout << input << '\n';
            list *x = input_list->next;
            if (x == input_list) {
                insert_front(input, input_list);
            }
            else {
                while (x != input_list) {
                    if (x->next != input_list && *(x->key) > input && *(x->next->key) <= input) {
                        //cout << "In if " << *(x->key) << " is @ " << x << '\n';
                        insert_in_list(input, x, input_list);
                        input = UINT_MAX;
                        break;
                    }
                    else if (x->next == input_list && *(x->key) > input) {
                        //cout << "In else if " << *(x->key) << " is @ " << x << '\n';
                        insert_in_list(input, x, input_list);
                        input = UINT_MAX;
                        break;
                    }
                    else {
                        //cout << "In else " << *(x->key) << " is @ " << x << '\n';
                        x = x->next;
                        continue;
                    }
                    x = x->next;
                }
                if (input != UINT_MAX) {
                    insert_front(input, input_list);
                    input = UINT_MAX;
                }
            }
        }
        else {
            //cout << "i\n";
            if (input_list->next == input_list) {
                insert_front(UINT_MAX, goods_list);
            }
            else {
                insert_front(*(input_list->next->key), goods_list);
            }
            delete_front(input_list);
            
        }
        //print_list(input_list);
        //cout << i << '\n';
    }
    //print_list(input_list);
    
    print_reverse(goods_list);
    
    free(goods_list);
    free(input_list);
}
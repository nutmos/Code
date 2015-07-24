#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _student {
    int student_class;
    int student_id;
}student;

typedef struct _list {
    struct _list *prev;
    student *key;
    struct _list *next;
}list;

student find_in_list(student *std, int id, int stdArraySize);
list *list_alloc();
student *student_alloc();
list *print_list(list *head);
list *insert_rear(list *head, student key);
list *insert_in_list(list *head, student key);
student pop(list *head);

int main() {
    int nc, ns;
    cin >> nc >> ns;
    student std[ns];
    for (int i = 0; i < ns; i++) {
        cin >> std[i].student_class >> std[i].student_id;
    }
    /*for (int i = 0; i < ns; i++) {
     cout << "i = " << i << " std[i].student_class = " << std[i].student_class << " std[i].student_id = " << std[i].student_id << endl;
     }*/
    list *queue_list = list_alloc();
    queue_list->next = queue_list;
    queue_list->prev = queue_list;
    queue_list->key = NULL;
    list *out_of_queue_list = list_alloc();
    out_of_queue_list->next = out_of_queue_list;
    out_of_queue_list->prev = out_of_queue_list;
    out_of_queue_list->key = NULL;
    char ch = '\0';
    while (ch != 'X') {
        cin >> ch;
        if (ch == 'E') {
            int id;
            cin >> id;
            student std_temp = find_in_list(std, id, ns);
            insert_in_list(queue_list, std_temp);
        }
        else if (ch == 'D') {
            student std_temp = pop(queue_list);
            insert_rear(out_of_queue_list, std_temp);
        }
        /*else if (ch == 'P') {
         cout << "queue list is" << endl;
         print_list(queue_list);
         cout << endl << "out_of_queue_list is" << endl;
         print_list(out_of_queue_list);
         cout << endl;
         }*/
    }
    print_list(out_of_queue_list);
}

list *list_alloc() {
    return (list *)malloc(sizeof(list));
}

student *student_alloc() {
    return (student *)malloc(sizeof(student));
}

student pop(list *head) {
    //printf("pop function started.\n");
    student std = *(head->next->key);
    head->next->next->prev = head;
    head->next = head->next->next;
    return std;
}

student find_in_list (student *std, int id, int stdArraySize) {
    //cout << "find_in_list function started." << endl;
    student std_temp;
    for (int i = 0; i < stdArraySize; i++) {
        //cout << "i = " << i << " std[i].student_class = " << std[i].student_class << " std[i].student_id = " << std[i].student_id << endl;
        if (std[i].student_id == id) {
            std_temp = std[i];
            break;
        }
    }
    //cout << "found student: " << std_temp.student_id << " class: " << std_temp.student_class << endl;
    return std_temp;
}

list *insert_rear(list *head, student key) {
    //printf("insert_rear function started.\n");
    list *x_temp = list_alloc();
    x_temp->key = student_alloc();
    *(x_temp->key) = key;
    if (head->next == head) {
        x_temp->next = head;
        x_temp->prev = head;
        head->next = x_temp;
        head->prev = x_temp;
    }
    else {
        x_temp->next = head;
        x_temp->prev = head->prev;
        head->prev->next = x_temp;
        head->prev = x_temp;
    }
}

list *insert_in_list(list *head, student key) {
    //cout << "insert_in_list function started." << endl;
    list *x_list = list_alloc();
    x_list->key = student_alloc();
    *(x_list->key) = key;
    list *x_ptr;
    x_ptr = head->next;
    while (x_ptr != head) {
        if (x_ptr->next == head) {
            //printf("x_ptr come in to if (x_ptr->next == head)\n");
            insert_rear(head, key);
            break;
        }
        else {
            //printf("x_ptr come in to else (x_ptr->next == head)\n");
            if (x_ptr->key->student_class == key.student_class) {
                //printf("x_ptr come in to if (x_ptr->key->student_class == key.student_class)\n");
                if (x_ptr->next != head) {
                    //printf("x_ptr come in to if (x_ptr->next != head)\n");
                    if (x_ptr->next->key->student_class != key.student_class) {
                        //printf("x_ptr come in to if (x_ptr->next->key->student_class != key.student_class)\n");
                        x_list->prev = x_ptr;
                        x_list->next = x_ptr->next;
                        x_ptr->next->prev = x_list;
                        x_ptr->next = x_list;
                        break;
                    }
                    else {
                        //printf("x_ptr come in to else (x_ptr->next->key->student_class != key.student_class)\n");
                        x_ptr = x_ptr->next;
                    }
                }
                else {
                    //printf("x_ptr come in to else (x_ptr->next != head)\n");
                    insert_rear(head, key);
                    break;
                }
            }
            else {
                //printf("x_ptr come in to else (x_ptr->key->student_id == key.student_id)\n");
                x_ptr = x_ptr->next;
            }
            //break;
        }
    }
    if (x_ptr == head) {
        insert_rear(head, key);
    }
}

list *print_list(list *head) {
    //printf("print_list function started.\n");
    list *x_ptr = head->next;
    if (head->next == head) {
        cout << "empty" << endl;
    }
    else {
        while (x_ptr != head) {
            cout << x_ptr->key->student_id << endl;
            x_ptr = x_ptr->next;
        }
        cout << '0' << endl;
    }
}
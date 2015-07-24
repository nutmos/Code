#include <iostream>
#include <cstdlib>

using namespace std;

struct atom {
    atom *prev;
    int energy;
    int diff;
    atom *next;
};

int sum_energy = 0;

int abs(int n) {
    return (n >= 0)?n:-n;
}

atom *atom_alloc (int n) {
    atom *new_a = (atom *)malloc(sizeof(atom));
    new_a->energy = n;
    new_a->diff = 0;
    new_a->prev = NULL;
    new_a->next = NULL;
    return new_a;
}

atom *delete_atom (atom *head) {
    int max = 0;
    atom *max_ptr = NULL;
    atom *a_ptr = head->next->next;
    while (a_ptr != head) {
        //cout << "test" << endl;
        if (a_ptr->diff > max) {
            max_ptr = a_ptr;
            max = a_ptr->diff;
        }
        a_ptr = a_ptr->next;
    }
    sum_energy += max;
    max_ptr->next->diff = abs(max_ptr->next->energy - max_ptr->prev->prev->energy);
    if (max_ptr != NULL) {
        max_ptr->prev->prev->next = max_ptr->next;
        max_ptr->next->prev = max_ptr->prev->prev;
    }
}

atom *print(atom *head) {
    atom *a_ptr = head->next;
    while (a_ptr != head) {
        cout << a_ptr->energy << ' ' << a_ptr->diff << endl;
        a_ptr = a_ptr->next;
    }
}

int main() {
    int n;
    cin >> n;
    atom *head = (atom*)malloc(sizeof(atom));
    head->next = head;
    head->prev = head;
    int energy;
    for (int i = 0; i < n; i++) {
        cin >> energy;
        atom *new_atom = atom_alloc(energy);
        new_atom->next = head;
        new_atom->prev = head->prev;
        head->prev->next = new_atom;
        head->prev = new_atom;
        if (new_atom->prev != head) {
            new_atom->diff = abs(new_atom->energy - new_atom->prev->energy);
        }
    }
    while (head->next->next != head) {
        delete_atom(head);
        //cout << endl;
        //print(head);
    }
    cout << sum_energy;
}

#include <iostream>
#include <cstdlib>

using namespace std;

int sumScore = 0;

struct book {
    int number;
    int sumdiff;
    book *prev;
    book *next;
};

class bookOper {
public:
    void print(book *b) {
        cout << "normal: ";
        book *bp = b->next;
        while (bp != b) {
            cout << bp->number << ' ' << bp->sumdiff << endl;
            bp = bp->next;
        }
        cout << "reverse: ";
        bp = b->prev;
        while (bp != b) {
            cout << bp->number << ' ' << bp->sumdiff << endl;
            bp = bp->prev;
        }
    }
    void insert(book *b, int n) {
        book *x = (book *)malloc(sizeof(book));
        x->sumdiff = 0;
        x->number = n;
        x->next = b->next;
        x->prev = b;
        b->next->prev = x;
        b->next = x;
    }
    void calculateSumDiff(book *b) {
        book *bp = b->next->next->next;
        while (bp != b) {
            cout << "test" << endl;
            bp->sumdiff = bp->number + bp->prev->number - bp->prev->prev->number;
            bp = bp->next;
        }
    }
    void grabBook (book *b) {
        bool haveMoreZero = false;
        book *bp1, *max;
        int maxNum;
        while (1) {
            cout << "test2" << endl;
            max = NULL;
            maxNum = 0;
            bp1 = b->next->next->next;
            while (bp1 != b) {
                if (bp1->sumdiff > maxNum) {
                    max = bp1;
                    maxNum = bp1->sumdiff;
                }
                bp1 = bp1->next;
            }
            cout << "maxNum = " << maxNum << endl;

            if (max == NULL) {
                break;
            }
            else {
                cout << "test3" << endl;
                sumScore += maxNum;
                cout << "sumScore = " << sumScore << endl;
                if (max->next != b) {
                    max->next->sumdiff = max->next->number + max->prev->prev->prev->number - max->prev->prev->prev->prev->number;
                }
                max->prev->prev->prev->next = max->next;
                max->next->prev = max->prev->prev->prev;
                free(max->prev);
                free(max);
                print(b);
            }
        }
    }
};

int main() {
    book *b = (book *)malloc(sizeof(book));
    b->next = b;
    b->prev = b;
    b->number = 0;
    b->sumdiff = 0;
    int n;
    int temp;
    bookOper bOper;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        bOper.insert(b, temp);
    }
    bOper.calculateSumDiff(b);
    bOper.print(b);
    bOper.grabBook(b);
    cout << sumScore;
}

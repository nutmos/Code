#include <iostream>

using namespace std;

typedef struct _domino {
    int position;
    int height;
    int pushRight;
    int pushLeft;
}domino;

void merge_sort(domino dom[], int index) {
    int index1 = index/2, index2 = (index%2==0)?index/2:(index/2)+1;
    //cout << "index1 = " << index1 << "index2 = " << index2 << endl;
    domino dom1[index1], dom2[index2];
    register int i;
    for (i = 0; i < index; i++) {
        (i < index1)?dom1[i] = dom[i]:dom2[i-(index/2)] = dom[i];
    }
    if (index1 != 1) merge_sort(dom1, index1);
    if (index2 != 1) merge_sort(dom2, index2);
    /*cout << "dom1: " << endl;
     for (i = 0; i < index1; i++) {
     cout << "i = " << i << ' ' << dom1[i].position << ' ' << dom1[i].height << endl;
     }
     cout << "dom2: " << endl;
     for (i = 0; i < index2; i++) {
     cout << "i = " << i << ' ' << dom2[i].position << ' ' << dom2[i].height << endl;
     }*/
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    while (1) {
        if (count == index) {
            break;
        }
        else if (count1 == index1 && count2 == index2) {
            break;
        }
        else if (count1 == index1 && count2 != index2) {
            dom[count] = dom2[count2];
            count2++;
        }
        else if (count1 != index1 && count2 == index2) {
            dom[count] = dom1[count1];
            count1++;
        }
        else {
            if (dom1[count1].position < dom2[count2].position) {
                dom[count] = dom1[count1];
                count1++;
            }
            else {
                //cout << "test1" << endl;
                dom[count] = dom2[count2];
                count2++;
            }
        }
        count++;
        //cout << "count1 = " << count1 << " count2 = " << count2 << " count = " << count << endl;
    }
    //cout << "Sorted" << endl;
    /*for (int i = 0; i < index; i++) {
     cout << "i = " << i << ' ' << dom[i].position << ' ' << dom[i].height << endl;
     }*/
    //cout << endl;
}

int main() {
    int n;
    cin >> n;
    domino dom[n];
    register int i;
    for (i = 0; i < n; i++) {
        cin >> dom[i].position >> dom[i].height;
    }
    /*for (i = 0; i < n; i++) {
     cout << dom[i].position << ' ' << dom[i].height << endl;
     }*/
    merge_sort(dom, n);
    /*cout << "End Merge Sort" << endl;
     for (i = 0; i < n; i++) {
     cout << "i = " << i << ' ' << dom[i].position << ' ' << dom[i].height << endl;
     }*/
    for (i = 0; i < n; i++) {
        //left
        int domPushedLeft = dom[i].position - dom[i].height;
        int count = 0;
        dom[i].pushLeft = 0;
        while (1) {
            count++;
            if (i-count < 0) break;
            else if (domPushedLeft < dom[i-count].position) {
                dom[i].pushLeft++;
            }
            else break;
            domPushedLeft -= dom[i-count].height;
        }
        //right
        dom[i].pushRight = 0;
        int domPushedRight = dom[i].position + dom[i].height;
        count = 0;
        while (1) {
            count++;
            if (i+count >= n) break;
            else if (domPushedRight > dom[i+count].position) {
                dom[i].pushRight++;
            }
            else break;
            domPushedRight += dom[i+count].height;
        }
        cout << "dom[i].PushLeft = " << dom[i].pushLeft << " dom[i].PushRight = " << dom[i].pushRight << endl;
    }
}

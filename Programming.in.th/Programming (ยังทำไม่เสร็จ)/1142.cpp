//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
//First Compile with Xcode 4.6.1
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct rent {
    int from;
    int to;
};

void merge_sort(rent array[], int n) {
	int index1 = n/2, index2 = (n % 2 == 0)?n/2:n/2+1;
    rent array1[index1], array2[index2];
    int i;
    for (i = 0; i < n; i++) {
        (i < index1)?array1[i] = array[i]:array2[i-(n/2)] = array[i];
    }
    /*cout << "Array 1 is" << endl;
     for (int i = 0; i < index1; i++) {
     cout << array1[i] << endl;
     }
     cout << "Array 2 is" << endl;
     for (int i = 0; i < index2; i++) {
     cout << array2[i] << endl;
     }*/
    if (index1 != 1) merge_sort(array1, index1);
    if (index2 != 1) merge_sort(array2, index2);
    for (int i = 0, j = 0, count = 0; count < n; count++) {
        if (i == index1 && j == index2) {
            break;
        }
        else if (i == index1 && j != index2) {
            array[count] = array2[j];
            j++;
        }
        else if (i != index1 && j == index2) {
            array[count] = array1[i];
            i++;
        }
        else {
            if (array1[i].from < array2[j].from) {
                array[count] = array1[i];
                i++;
            }
            else {
                array[count] = array2[j];
                j++;
            }
        }
    }
    /*cout << "Sorted" << endl;
     for (int i = 0; i < n; i++) {
     cout << array[i] << endl;
     }*/
}

int main() {
    int company, perDay;
    scanf("%d %d",&company, &perDay);
    rent array[company];
    for (int i = 0; i < company; i++) {
        scanf("%d %d",&array[i].from, &array[i].to);
    }
    merge_sort(array, company);
    /*printf("sorted\n");
    for (int i = 0; i < company; i++) {
        printf("%d %d\n", array[i].from, array[i].to);
    }*/
    int *companyOutAt = (int *)calloc(sizeof(int), perDay);
    int day = 1;
    int index = 0;
    while (index != company) {
        //printf("%d\n", day);
        while (array[index].from == day) {
            int status = 0;
            for (int i = 0; i < perDay; i++) {
                if (companyOutAt[i] == 0) {
                    printf("yes\n");
                    companyOutAt[i] = array[index].to;
                    status = 1;
                    break;
                }
            }
            if (status == 0) {
                printf("no\n");
            }
            ++index;
        }
        if (index == company) {
            break;
        }
        for (int i = 0; i < perDay; i++) {
            if (companyOutAt[i] == day) {
                companyOutAt[i] = 0;
                break;
            }
        }
        ++day;
    }
}
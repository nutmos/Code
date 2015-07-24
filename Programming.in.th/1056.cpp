#include <iostream>

using namespace std;

void merge_sort(int array[], int numberOfElementsInArray);

int main() {
    int n,k;
    cin >> n >> k;
    register int i;
    int array[n];
    for (i = 0; i < n; i++) {
        cin >> array[i];
    }
    merge_sort(array, n);
    //cout << endl;
    /*for (i = 0; i < n; i++) {
        cout << array[i] << endl;
    }*/
    int arrayCount = 0;
    int sumTime = 0;
    while (arrayCount < n) {
        //cout << arrayCount << endl;
        sumTime += array[arrayCount];
        //cout << "array = " << array[arrayCount] << endl;
        arrayCount += k;
    }
    //cout << endl;
    cout << sumTime;
    return 0;
}

void merge_sort(int array[], int numberOfElementsInArray) {
    int index1 = numberOfElementsInArray/2, index2 = (numberOfElementsInArray%2 == 0)?numberOfElementsInArray/2:numberOfElementsInArray/2+1;
    int array1[index1], array2[index2];
    register int i,j,count;
    //cout << endl;
    for (i = 0; i < numberOfElementsInArray; i++) {
        (i < numberOfElementsInArray/2)?array1[i] = array[i]:array2[i-numberOfElementsInArray/2] = array[i];
        //if (i < numberOfElementsInArray/2) cout << array1[i];
        //else cout << array2[i-numberOfElementsInArray/2];
        //cout << endl;
    }
    if (index1 != 1) merge_sort(array1, index1);
    if (index2 != 1) merge_sort(array2, index2);
    //cout << endl;
    for (i = 0, j = 0, count = 0; count < numberOfElementsInArray; count++) {
        if (i == index1 && j != index2) {
            array[count] = array2[j];
            j++;
        }
        else if (i != index1 && j == index2) {
            array[count] = array1[i];
            i++;
        }
        else {
            if (array1[i] > array2[j]) {
                array[count] = array1[i];
                i++;
            }
            else {
                array[count] = array2[j];
                j++;
            }
        }
        //cout << array[count] << endl;
    }
}

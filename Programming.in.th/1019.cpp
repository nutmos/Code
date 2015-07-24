#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define A 0
#define T 1
#define C 2
#define G 3

using namespace std;

bool strcmpByPart(char str1[], char str2[], int start1, int end1, int start2, int end2) {
    /*printf("str1 = ");
    for (int i = start1; i <= end1; ++i) {
        printf("%c",str1[i]);
    }
    printf("\n");
    printf("str2 = ");
    for (int i = start2; i <= end2; ++i) {
        printf("%c",str2[i]);
    }
    printf("\n");*/
    for (int i = start1, j = start2; i <= end1 && j <= end2; ++i, ++j) {
        if (str1[i] != str2[j]) {
            return false;
        }
    }
    return true;
}

bool isTwoArrayEqual(int arr1[], int arr2[]) {
    if (arr1[0] == arr2[0] && arr1[1] == arr2[1] && arr1[2] == arr2[2] && arr1[3] == arr2[3]) {
        return true;
    }
    else return false;
}

void strcpyPart(char str1[], int from, int to, char strTmp[], int *len) {
    //printf("strcpyByPart func started.\n");
    for (int i = 0; i < to-from+1; ++i) {
        strTmp[i] = str1[from+i];
    }
    strTmp[to-from+1] = '\0';
    *len = to-from+1;
}

int main() {
    char str1[200];
    char str2[200];
    scanf("%s %s",str1,str2);
    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);
    int count1[4], count2[4];
    int len;
    int lenOfRepeatStr = 0;
    char repeatStr[200];
    for (int i = 0; i < len1; ++i) {
        count1[0] = 0; count1[1] = 0; count1[2] = 0; count1[3] = 0;
        switch (str1[i]) {
            case 'A':
                count1[A] = 1;
                break;
            case 'T':
                count1[T] = 1;
                break;
            case 'C':
                count1[C] = 1;
                break;
            case 'G':
                count1[G] = 1;
                break;
            default:
                break;
        }
        for (int j = i+1; j < len1; ++j) {
            switch (str1[j]) {
                case 'A':
                    count1[A] += 1;
                    break;
                case 'T':
                    count1[T] += 1;
                    break;
                case 'C':
                    count1[C] += 1;
                    break;
                case 'G':
                    count1[G] += 1;
                    break;
                default:
                    break;
            }
            len = j-i+1;
            //printf("len = %d\n",len);
            count2[0] = 0; count2[1] = 0; count2[2] = 0; count2[3] = 0;
            for (int k = 0; k < len; ++k) {
                switch (str2[k]) {
                    case 'A':
                        count2[A] += 1;
                        break;
                    case 'T':
                        count2[T] += 1;
                        break;
                    case 'C':
                        count2[C] += 1;
                        break;
                    case 'G':
                        count2[G] += 1;
                        break;
                    default:
                        break;
                }
            }
            if (isTwoArrayEqual(count1, count2) && lenOfRepeatStr < len) {
                if (strcmpByPart(str1, str2, i, j, 0, len-1)) {
                    strcpyPart(str1, i, j, repeatStr,&lenOfRepeatStr);
                }
            }
            for (int k = len; k < len2; ++k) {
                switch (str2[k]) {
                    case 'A':
                        count2[A] += 1;
                        break;
                    case 'T':
                        count2[T] += 1;
                        break;
                    case 'C':
                        count2[C] += 1;
                        break;
                    case 'G':
                        count2[G] += 1;
                        break;
                    default:
                        break;
                }
                switch (str2[k-len]) {
                    case 'A':
                        count2[A] -= 1;
                        break;
                    case 'T':
                        count2[T] -= 1;
                        break;
                    case 'C':
                        count2[C] -= 1;
                        break;
                    case 'G':
                        count2[G] -= 1;
                        break;
                    default:
                        break;
                }
                if (isTwoArrayEqual(count1, count2) && lenOfRepeatStr < len) {
                    if (strcmpByPart(str1, str2, i, j, k-len+1, k)) {
                        strcpyPart(str1, i, j, repeatStr,&lenOfRepeatStr);
                    }
                }
            }
        }
    }
    printf("%s",repeatStr);
}
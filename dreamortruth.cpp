#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    char input1[301],input2[301],inputAns[601];
    int *ansCalculate = (int *)calloc(sizeof(int), 601);
    scanf("%s",input1);
    scanf("%s",input2);
    scanf("%s",inputAns);
    int len1 = (int)strlen(input1);
    int len2 = (int)strlen(input2);
    int indexAnsCalculate = 600;
    int tmp = 0, n1, n2, index_tmp,tmptmp;
    for (int i = len1-1; i >= 0; --i,--indexAnsCalculate) {
        tmp = 0;
        index_tmp = indexAnsCalculate;
        for (int j = len2-1; j >= 0; --j,--index_tmp) {
            n1 = input1[i]-'0';
            n2 = input2[j]-'0';
            tmptmp = n1*n2;
            ansCalculate[index_tmp] += (tmptmp % 10) + tmp;
            int newIndex_tmp = index_tmp;
            while (ansCalculate[newIndex_tmp] >= 10) {
                
                --newIndex_tmp;
            }
            tmp = tmptmp/10;
        }
        while (tmp > 0 && index_tmp >= 0) {
            //printf("index_tmp = %d\n",index_tmp);
            ansCalculate[index_tmp] += tmp%10;
            tmp = ansCalculate[index_tmp]/10;
            --index_tmp;
        }
        /*for (int j = 0; j < 601; ++j) {
         printf("%d ",ansCalculate[j]);
         }
         printf("\n");*/
    }
    int indexNew = 0;
    int minIndex = 600;
    for (int i = 600; i > 0; --i) {
        if (ansCalculate[i] >= 10) {
            //printf("ansCalculate[i] = %d\n",ansCalculate[i]);
            ansCalculate[i-1] += ansCalculate[i]/10;
            ansCalculate[i] %= 10;
        }
        if (ansCalculate[i] > 0) {
            minIndex = i;
        }
    }
    /*for (int i = 0; i < 601; ++i) {
     printf("%d ",ansCalculate[i]);
     }
     printf("\n");*/
    char new_ansCalculate[601];
    for (int i = minIndex; i <= 600; ++i, ++indexNew) {
        new_ansCalculate[indexNew] = ansCalculate[i] + '0';
    }
    new_ansCalculate[indexNew] = '\0';
    //printf("%s\n%s\n",ansCalculate,inputAns);
    printf("%s\n",(strcmp(new_ansCalculate, inputAns) == 0)?"truth":"dream");
}
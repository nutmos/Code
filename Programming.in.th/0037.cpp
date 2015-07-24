#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n1,n2,n3,n4,n5,tmp;
    scanf("%d %d",&n1,&n2);
    scanf("%d %d",&n3,&n4);
    scanf("%d",&n5);
    int sum = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            scanf("%d",&tmp);
            sum += tmp;
        }
    }
    sum += n3*n4*n5;
    //printf("%d\n",sum);
    if (sum % n5 == 0) {
        printf("%d",sum/n5);
    }
    else {
        printf("%d",(sum/n5)+1);
    }
}
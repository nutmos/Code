#include <iostream>
#include <cstdio>
#include <cstdlib>
#define R 0
#define O 1

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int count[2];
    char str[n+1];
    scanf("%s",str);
    int maximumPossible = (n/(m+1))*(m+1);
    int **counting = new int*[maximumPossible];
    //printf("%d",maximumPossible);
    for (int i = 0; i < maximumPossible; ++i) {
    	counting[i] = new int[2];
    	if (i != 0) {
    		counting[i][0] = counting[i-1][0];
    		counting[i][1] = counting[i-1][1];
    	}
    	else {
    		counting[i][0] = 0;
    		counting[i][1] = 0;
    	}
    	if (str[i] == 'R') {
    		counting[i][R]++;
    	}
    	else {
    		counting[i][O]++;
    	}
    }
    for (int i = maximumPossible; i >= m+1; i -= m+1) {
    	count[R] = counting[i-1][R];
    	count[O] = counting[i-1][O];
    	if (count[O] >= count[R]) {
            if (count[O] == m*count[R]) {
                printf("%d",i);
                return 0;
            }
        }
        //printf("%d %d\n",count[R],count[O]);
        for (int j = i; j < n; ++j) {
            if (str[j] == 'R') {
                ++count[R];
            }
            else {
                ++count[O];
            }
            if (str[j-i] == 'R') {
                --count[R];
            }
            else {
                --count[O];
            }
            if (count[O] >= count[R]) {
                if (count[O] == m*count[R]) {
                    printf("%d",i);
                    return 0;
                }
            }
            //printf("%d %d\n",count[R],count[O]);
        }
    }
    printf("0");
}
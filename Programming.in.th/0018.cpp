 #include <iostream>

using namespace std;

int main(){
	int k,n,i,count=0,multiply,j;
	cin >> n >> k;
	int array[n+1];
	for (i = 0; i < n+1; i++){
		array[i] = i;
	}
    
	for (i = 2; i <= n; i++) {
        if (array[i] > 0) {
            multiply = 1;
            for (j = 1; ; j++) {
                multiply = i * j;
                if (multiply > n) {
                    break;
                }
                if (array[multiply] > 0) {
                    count--;
                    array[multiply] = count;
                }
            }
        }
    }
    
    /*for (i = 0; i < n+1; i++) {
     std::cout << array[i] << ' ';
     }*/
    for (i = 2; i < n+1; i++) {
        if (array[i] == -k) {
            cout << i;
        }
    }
	return 0;			
}
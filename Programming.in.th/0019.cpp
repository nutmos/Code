#include <iostream>
#include <math.h>

int to_base_2(int base10, int n){
    unsigned int ans = 0, base2[n],i;
    
    for(i=0; i < n; i++)
    {
        base2[i] = base10 % 2;
        base10 = base10 / 2;
    }
    
    for (i = 0; i < n; i++) {
        ans = ans + (base2[i] * pow(10,i));
    }
    
    return ans;
}

int main(){
    int n,base2,po,bitint,temp;
    double bit;
    int i,j;
    
    std::cin >> n;
    
   	int s[n],b[n];
    
    po = pow(2,n);
    
    base2 = pow(10,n);
    
    for (i = 0; i < n; i++) {
        std::cin >> s[i] >> b[i];
    }
    
    int base2array[po];
    
	int sums[po],sumb[po],sum[po];
    
	for (i = 0; i < po; i++){
		sums[i] = 1;
		sumb[i] = 0;
	}
    
    for (i = 0; i < po; i++) {
        base2array[i] = to_base_2(i, n);
        for (j = 0; j < n; j++) {
            bit = fmod((base2array[i] / pow(10,j)), 10);
            bitint = (int)bit;
            if (bitint == 1){
				sums[i] = sums[i] * s[j];
				sumb[i] = sumb[i] + b[j];
            }
        }
    }
	
	for (i = 0; i < po; i++){
		//sum[i] = abs(sums[i] - sumb[i]);
		if (sums[i] > sumb[i]) sum[i] = sums[i] - sumb[i];
		else sum[i] = sumb[i] - sums[i];
	}
	
	for (i = 1; i < po; i++){
		for (j = i+1; j < po; j++){
			if (sum[i] > sum[j]){
				temp = sum[i];
				sum[i] = sum[j];
				sum[j] = temp;
			}
		}
	}
	
	std::cout << sum[1];
	/*for (i = 0; i < po; i++){
		std::cout << sum[i] << ' ';
	}*/
    
    return 0;
}


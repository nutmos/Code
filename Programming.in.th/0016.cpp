#include <iostream>

void adrian_answer(char ans[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (i % 3 == 0) ans[i] = 'A';
		else if (i % 3 == 1) ans[i] = 'B';
		else if (i % 3 == 2) ans[i] = 'C';
	}
}

void bruno_answer(char ans[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (i % 4 == 0 || i % 4 == 2) ans[i] = 'B';
		else if (i % 4 == 1) ans[i] = 'A';
		else if (i % 4 == 3) ans[i] = 'C';
	}
}

void goran_answer(char ans[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (i % 6 == 0 || i % 6 == 1) ans[i] = 'C';
		else if (i % 6 == 2 || i % 6 == 3) ans[i] = 'A';
		else if (i % 6 == 4 || i % 6 == 5) ans[i] = 'B';
	}
}

int main(){
	int n,i;
	std::cin >> n;
	char ans[n];
    std::cin >> ans;
	char adrian_ans[n],bruno_ans[n],goran_ans[n];
	int adrian=0, bruno=0, goran=0,max=0;
	adrian_answer(adrian_ans,n);
	bruno_answer(bruno_ans,n);
	goran_answer(goran_ans,n);
    
    /*for (i = 0; i < n; i++) {
     std::cout << adrian_ans[i] << ' ';
     }
     std::cout << '\n';
     for (i = 0; i < n; i++) {
     std::cout << bruno_ans[i] << ' ';
     }
     std::cout << '\n';
     for (i = 0; i < n; i++) {
     std::cout << goran_ans[i] << ' ';
     }*/
	
	for (i = 0; i < n; i++){
        if (ans[i] == adrian_ans[i]) adrian++;
        if (ans[i] == bruno_ans[i]) bruno++;
        if (ans[i] == goran_ans[i]) goran++;
    }
	
    max = adrian;
    if (bruno > max) max = bruno;
    if (goran > max) max = goran;
    
    std::cout << max << '\n';
    if (adrian == max) std::cout << "Adrian" << '\n';
    if (bruno == max) std::cout << "Bruno" << '\n';
    if (goran == max) std::cout << "Goran" << '\n';
}
#include <iostream>
#include <cstdio>

using namespace std;

//1 = top left
//2 = bottom right
//3 = top right
//4 = bottom left

struct range {
	int x1,y1,x2,y2,x3,y3,x4,y4;
};

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	range frame[n], paper[m];
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d",&frame[i].x1,&frame[i].y1,&frame[i].x2,&frame[i].y2);
		frame[i].x3 = frame[i].x2;
		frame[i].y3 = frame[i].y1;
		frame[i].x4 = frame[i].x1;
		frame[i].y4 = frame[i].y2;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d",&paper[i].x1,&paper[i].y1,&paper[i].x2,&paper[i].y2);
		paper[i].x3 = paper[i].x2;
		paper[i].y3 = paper[i].y1;
		paper[i].x4 = paper[i].x1;
		paper[i].y4 = paper[i].y2;
	}
	for (int i = 0; i < m; ++i) {
		int count = 0;
		for (int j = 0; j < n; ++j) {
			if (paper[i].x1 >= frame[j].x1 &&
				paper[i].x1 < frame[j].x2 &&
				paper[i].y1 <= frame[j].y1 &&
				paper[i].y1 > frame[j].y2) {
				//printf("1 j = %d\n",j);
				++count;
			}
			else if (paper[i].x2 > frame[j].x1 &&
				paper[i].x2 <= frame[j].x2 &&
				paper[i].y2 < frame[j].y1 &&
				paper[i].y2 >= frame[j].y2) {
				//printf("2 j = %d\n",j);
				++count;
			}
			else if (paper[i].x3 <= frame[j].x3 &&
				paper[i].x3 > frame[j].x4 &&
				paper[i].y3 <= frame[j].y3 &&
				paper[i].y3 > frame[j].y4) {
				//printf("3 j = %d\n",j);
				++count;
			}
			else if (paper[i].x4 < frame[j].x3 &&
				paper[i].x4 >= frame[j].x4 &&
				paper[i].y4 < frame[j].y3 &&
				paper[i].y4 >= frame[j].y4) {
				//printf("4 j = %d\n",j);
				++count;
			}
			else if (paper[i].x1 < frame[j].x1 &&
				paper[i].x3 > frame[j].x2 &&
				paper[i].y1 > frame[j].y2 &&
				paper[i].y1 <= frame[j].y3){
				//printf("5 j = %d\n",j);
				++count;
			}
			else if (paper[i].x4 < frame[j].x2 &&
				paper[i].x2 > frame[j].x3 &&
				paper[i].y4 >= frame[j].y2 &&
				paper[i].y4 < frame[j].y3) {
				//printf("6 j = %d\n",j);
				++count;
			}
			else if (paper[i].y1 > frame[j].y1 &&
				paper[i].y4 < frame[j].y4 &&
				paper[i].x1 >= frame[j].x1 &&
				paper[i].x1 < frame[j].x3) {
				//printf("7 j = %d\n",j);
				++count;
			}
			else if (paper[i].y3 > frame[i].y1 &&
				paper[i].y2 < frame[i].y4 &&
				paper[i].x3 > frame[i].x1 &&
				paper[i].x3 <= frame[i].x3) {
				//printf("8 j = %d\n",j);
				++count;
			}
		}
		printf("%d\n",count);
	}
}
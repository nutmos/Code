#include <iostream>
#include <cstdio>
#include <cstring>
#define N 'N'
#define E 'E'
#define W 'W'
#define S 'S'
#define LEFT 'L'
#define RIGHT 'R'
#define BACK 'B'
#define DEAD 0
#define ALIVE 1

using namespace std;

bool isDead(int n) {
	if (n >= 50000 || n <= -50000) {
		return DEAD;
	}
	else {
		return ALIVE;
	}
}

char turnTo(char headedTo, char turn) {
	if (turn == LEFT) {
		switch(headedTo) {
			case N:return W; break;
			case E:return N; break;
			case W:return S; break;
			case S:return E; break;
			default:break;
		}
	}
	else if (turn == RIGHT) {
		switch(headedTo) {
			case N:return E; break;
			case E:return S; break;
			case W:return N; break;
			case S:return W; break;
			default:break;
		}
	}
	else if (turn == BACK) {
		switch(headedTo) {
			case N:return S; break;
			case E:return W; break;
			case W:return E; break;
			case S:return N; break;
			default:break;
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int x = 0, y = 0;
	char headedTo = E;
	char command[3];
	int dist;
	bool status = ALIVE;
	for (int i = 0; i < n; ++i) {
		scanf("%s %d",command, &dist);
		if (status == ALIVE) {
			if (command[0] == 'F') {
				if (headedTo == N) {
					status = isDead(y + dist);
					if (status != DEAD) y += dist;
				}
				else if (headedTo == E) {
					status = isDead(x + dist);
					if (status != DEAD) x += dist;
				}
				else if (headedTo == W) {
					status = isDead(x - dist);
					if (status != DEAD) x -= dist;
				}
				else if (headedTo == S) {
					status = isDead(y - dist);
					if (status != DEAD) y -= dist;
				}
			}
			else if (command[0] == 'R') {
				headedTo = turnTo(headedTo, RIGHT);
				if (headedTo == N) {
					status = isDead(y + dist);
					if (status != DEAD) y += dist;
				}
				else if (headedTo == E) {
					status = isDead(x + dist);
					if (status != DEAD) x += dist;
				}
				else if (headedTo == W) {
					status = isDead(x - dist);
					if (status != DEAD) x -= dist;
				}
				else if (headedTo == S) {
					status = isDead(y - dist);
					if (status != DEAD) y -= dist;
				}
			}
			else if (command[0] == 'L') {
				headedTo = turnTo(headedTo, LEFT);
				if (headedTo == N) {
					status = isDead(y + dist);
					if (status != DEAD) y += dist;
				}
				else if (headedTo == E) {
					status = isDead(x + dist);
					if (status != DEAD) x += dist;
				}
				else if (headedTo == W) {
					status = isDead(x - dist);
					if (status != DEAD) x -= dist;
				}
				else if (headedTo == S) {
					status = isDead(y - dist);
					if (status != DEAD) y -= dist;
				}
			}
			else if (command[0] == 'B') {
				headedTo = turnTo(headedTo, BACK);
				if (headedTo == N) {
					status = isDead(y + dist);
					if (status != DEAD) y += dist;
				}
				else if (headedTo == E) {
					status = isDead(x + dist);
					if (status != DEAD) x += dist;
				}
				else if (headedTo == W) {
					status = isDead(x - dist);
					if (status != DEAD) x -= dist;
				}
				else if (headedTo == S) {
					status = isDead(y - dist);
					if (status != DEAD) y -= dist;
				}
			}
		}
	}
	if (status == ALIVE) {
		printf("%d %d\n%c",x,y,headedTo);
	}
	else printf("DEAD");
}
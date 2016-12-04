#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define LENGTH 100

/*function prototype*/
void nQueens(int i, int n);
bool promising(int i);

/*global variable*/
int col[LENGTH];
int solcnt = 0;

void main() {
	int n;
		scanf_s("%d", &n);
		nQueens(0, n);
		printf("%d", solcnt);
		getchar();
		getchar();
}

void nQueens(int i, int n) {

	int j;
	if (!promising(i)) return;
	
	if (i == n) {
		solcnt++;
	}
	else {
		for (j = 1; j <n+1; j++) {
			col[i + 1] = j;
			nQueens(i + 1, n);
		}
	}

}

bool promising(int i) {
	int k;
	for (k = 1; k < i; k++) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k )
			return false;
	}
	return true;
}



#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define LENGTH 100

/*function prototype*/
void nQueens(int i, int n);
bool promising(int i);

/*global variable*/
int col[LENGTH];

void main() {

	int n;

	while (true) {
		scanf_s("%d", &n);
		nQueens(0, n);
	}

}

void nQueens(int i, int n) {

	if (!promising(i)) return;
	
	if (i == n) {
		for (int j=1; j <= n; j++) {
			printf("%d", col[j]);
		}
		printf("\n");
	}
	else {
		for (int j = 1; j <= n; j++) {
			col[i + 1] = j;
			nQueens(i + 1, n);
		}
	}

}

bool promising(int i) {
	
	for (int j = 0; j < i; j++) {
		if (col[i] == col[j] || abs(col[i] - col[j]) == i - j)
			return false;
		return true;
	}

}
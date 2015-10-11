#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/*
	动态规划解计算最小编辑距离，又称Levenshtein距离。
	d[i,j] = min{ d[i-1,j] + 1, d[i, j-1] + 1, d[i-1, j-1] + f_ij }
	f_ij = 0 where a_i == b_j 
	f_ij = 1 where a_i != b_j
*/

int **d;

int dist(char *a, char *b){
	int i = strlen(a);
	int j = strlen(b);
	d[0][0] = 0;
	for(int l = 0; l < j; l++){
		d[0][l] = l;
	}
	for(int l = 0; l < i; l++){
		d[l][0] = l;
	}
	for(int row = 1; row <= i; row++){
		for(int col = 1; col <= j; col++){
			if(a[row-1] == b[col-1]){
				int t1 = d[row-1][col]+1;
				int t2 = d[row][col-1]+1;
				int t3 = d[row-1][col-1];
				int tmp = t1 < t2 ? t1: t2;
				d[row][col] = t3 < tmp ? t3 : tmp;
			}
			else{
				int t1 = d[row-1][col]+1;
				int t2 = d[row][col-1]+1;
				int t3 = d[row-1][col-1]+1;
				int tmp = t1 < t2 ? t1: t2;
				d[row][col] = t3 < tmp ? t3 : tmp;
			}
		}
	}

	return 0;
}

int main(){
	char a[] = "rosettacode";
	char b[] = "raisethysword";
	d = (int **)malloc(100 * sizeof(int *));
	for(int i = 0; i < 100; i++){
		d[i] = (int *)malloc(100 * sizeof(int));
	}

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			d[i][j] = 0;
		}
	}

	dist(a, b);
	printf("%d", d[strlen(a)][strlen(b)]);

	for(int i = 0; i < 100; i++){
		free(d[i]);
	}
	free(d);
	return 0;
}
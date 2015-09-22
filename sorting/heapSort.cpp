#include <iostream>
using namespace std;

void sift(int a[], int low, int high){
	int tmp = a[low];
	int i = low, j = i * 2;
	while(j <= high){
		if(j < high && a[j] < a[j+1])
			j++;
		if(tmp < a[j]){
			a[i] = a[j];
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
	a[i] = tmp;
}

void heapSort(int a[], int n){
	for(int i = n/2; i >= 1; i--){
		sift(a, i, n);
	}
	for(int i = n; i >= 2; i--){
		int tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;
		sift(a, 1, i-1);
	}
}



int main(){
	int N;
	while(cin >> N){
		int *a = new int[N+1];
		a[0] = 0;
		for(int i = 1; i < N+1; i++){
			cin >> a[i];
		}
		heapSort(a, N);
		for(int i = 1; i < N; i++){
			cout << a[i] << ' ';
		}
		cout << a[N] << endl;
		delete[] a;
	}
}
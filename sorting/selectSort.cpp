#include <iostream>

void selectSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		int min = a[i], idx = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < min){
				min = a[j];
				idx = j;
			}
		}
		a[idx] = a[i];
		a[i] = min;
	}
}

int main(){
	int N;
	while(cin >> N){
		int *a = new int[N];
		for(int i = 0; i < N; i++){
			cin >> a[i];
		}
		selectSort(a, 0, N-1);
		for(int i = 0; i < N-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[N-1] << endl;
		delete[] a;
	}
}
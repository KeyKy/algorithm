#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j > 0; j--){
			if(a[j-1] > a[j]){
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

int main(){
	int N;
	while(cin >> N){
		int *a = new int[N];
		for(int i = 0; i < N; i++){
			cin >> a[i];
		}
		insertionSort(a, 0, N-1);
		for(int i = 0; i < N-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[N-1] << endl;
		delete[] a;
	}
}
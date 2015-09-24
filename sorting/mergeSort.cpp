#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right){
	int *tmp = new int[right - left + 1]; int length = 0;
	int i = left;
	int j = mid+1;
	while(i <= mid && j <= right){
		if(a[i] > a[j]){
			tmp[length++] = a[j];
			j++;
		}
		else{
			tmp[length++] = a[i];
			i++;
		}
	}
	while(i <= mid){
		tmp[length++] = a[i];
		i++;
	}
	while(j <= right){
		tmp[length++] = a[j];
		j++;
	}
	for(int k = left, l = 0; k < left+length; k++, l++){
		a[k] = tmp[l];
	}
}

void mergeSort(int a[], int left, int right){
	if(left < right){
		int mid = (right + left) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int N;
	while(cin >> N){
		int *a = new int[N];
		for(int i = 0; i < N; i++){
			cin >> a[i];
		}
		mergeSort(a, 0, N-1);
		for(int i = 0; i < N-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[N-1] << endl;
		delete[] a;
	}
}
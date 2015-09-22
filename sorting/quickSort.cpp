#include <iostream>
using namespace std;

int partition(int a[], int left, int right){
	int pivot = a[left];
	int i = left, j = right;
	while(i < j){
		while(i < j && a[j] >= pivot)
			j--;
		while(i < j && a[i] <= pivot)
			i++;
		if(i < j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[left] = a[i];
	a[i] = pivot;
	return i;

}

void quickSort(int a[], int left, int right){
	if(left < right){
		int mid = partition(a, left, right);
		quickSort(a, left, mid);
		quickSort(a, mid+1, right);
	}
}

int main(){
	int N;
	while(cin >> N){
		int *a = new int[N];
		for(int i = 0; i < N; i ++){
			cin >> a[i];
		}
		quickSort(a, 0, N-1);
		for(int i = 0; i < N-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[N-1] << endl;
		delete[] a;
	}
}
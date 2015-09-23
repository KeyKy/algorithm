#include <iostream>
#include <vector>

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

void quickSort_unRec(int a[], int left, int right){
	pair<int, int> st[1000]; int top = -1;
	st[++top] = make_pair(left,right);
	while(top != -1){
		pair<int, int> margin = st[top--];
		int mid = partition(a, margin.first, margin.second);
		if(mid+1 <= margin.second){
			st[++top] = make_pair(mid+1, margin.second);
		}
		if(margin.first <= mid-1){
			st[++top] = make_pair(margin.first, mid-1);
		}
	}
}

int main(){
	int N;
	while(cin >> N){
		int *a = new int[N];
		for(int i = 0; i < N; i ++){
			cin >> a[i];
		}
		quickSort_unRec(a, 0, N-1);
		for(int i = 0; i < N-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[N-1] << endl;
		delete[] a;
	}
}
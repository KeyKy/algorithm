#include <iostream>
using namespace std;

struct{
	int i;
	int j;
	int di;
}st[1000];
int top = -1;

int main(){
	int i, j, di, find = 0;
	int x0 = 1, y0 = 1, xe = 3, ye = 3;
	i = x0; j = y0; di = -1;
	top++;
	st[top].i = i; st[top].j = j; st[top].di = di; 
	int mg[5][5] = {
					 {1,1,1,1,1},
					 {1,0,0,0,1},
					 {1,0,1,0,1},
					 {1,0,0,0,1},
					 {1,1,1,1,1}
					};
	mg[1][1] = 1; //初始化的时候记得[1][1]也要置为走过
	while(top != -1){
		i = st[top].i; j = st[top].j; di = st[top].di;
		if(i == xe && j == ye){
			for(int k = 0; k <= top; k++){
				cout << st[k].i << ',' << st[k].j << ' ';
			}
			cout << endl;
		}
		find = 0;
		while(di < 4 && !find){
			di++;
			switch(di){
			case 0: i = st[top].i; j = st[top].j+1; break; //di从0开始
			case 1: i = st[top].i+1; j = st[top].j; break;
			case 2: i = st[top].i-1; j = st[top].j; break;
			case 3: i = st[top].i; j = st[top].j-1; break;
			}
			if(mg[i][j] == 0) find = 1;
		}

		if(find){
			st[top].di = di;
			top++;
			st[top].i = i; st[top].j = j; mg[i][j] = 1; st[top].di = -1;
		}
		else{
			mg[st[top].i][st[top].j] = 0; //这里记得是当前的要重置为0，而不是i,j下一步重置为0
			top--;
		}
	}
	cin >> i;
}
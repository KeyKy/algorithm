#include <iostream>
using namespace std;

struct{
    int i;
    int j;
    int di;
}st[10000];

int top = -1;

int mg[5][5] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,1,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}
};

int main(){
    int xi = 1, yi = 1, xe = 3, ye = 3;
    int di = -1; int find = 0;
    top++;
    st[top].i = xi; st[top].j = yi; st[top].di = di;
    int i, j;
    mg[1][1] = 1;
    while(top != -1){
        i = st[top].i; j = st[top].j; di = st[top].di;
        if(i == xe && j == ye){
            for(int idx = 0; idx <= top; idx++)
                cout << st[idx].i << ',' << st[idx].j << ' ';
            cout << endl;
            di = st[top].di = 4;
        }
        find = 0;
        while(di < 4 && !find){
            di++;
            switch(di){
                case 0:i=st[top].i; j=st[top].j+1; break;
                case 1:i=st[top].i+1; j=st[top].j; break;
                case 2:i=st[top].i; j=st[top].j-1; break;
                case 3:i=st[top].i-1; j=st[top].j; break;
            }
            if(mg[i][j] == 0){
                find = 1;
            }
        }
        if(find){
            st[top].di = di;
            mg[i][j] = 1;
            top++;
            st[top].i = i; st[top].j = j; st[top].di = -1;
        }
        else{
            mg[st[top].i][st[top].j] = 0;
            top--;
        }
    }
    cin >> xi;
    return 0;
}
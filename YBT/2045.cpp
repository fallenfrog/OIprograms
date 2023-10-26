#include<iostream>
using namespace std;
int a[25][25],n,i,x,y;

int main(){
	cin >> n;
	a[x=n-1][y=0] = i = 1;
	while(i<n*n){
		while(a[x][y+1]==0&&y<n-1) a[x][++y] = ++i;
		while(a[x-1][y]==0&&x>0)a[--x][y] = ++i;
		while(a[x][y-1]==0&&y>0)a[x][--y] = ++i;
		while(a[x+1][y]==0&&x<n-1) a[++x][y] = ++i;
	}
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			cout << a[k][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

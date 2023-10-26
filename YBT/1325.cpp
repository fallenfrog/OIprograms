#include<bits/stdc++.h>
#define N 1004
using namespace std;
int m,a[N][N];

int main(){
	cin >> m;
	a[1][1] = 1;
	for(int k=1,h=1;k<=m;k++,h<<=1){
		for(int i=1;i<=h;i++){
			for(int j=1;j<=h;j++){
				a[i][j+h] = a[j+h][i] = a[i][j]+h;
				a[i+h][j+h] = a[i][j];
			}
		}
	}
	for(int i=1;i<=(1<<m);i++){
		for(int j=1;j<=(1<<m);j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

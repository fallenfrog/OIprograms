#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a[13][13];

int stl(int m,int n){
	if(a[m][n]!=0)	return a[m][n];
	if(m<=0 || n<=1)	return 1;
	if(n>m)	return stl(m,m);
	return stl(m,n-1)+stl(m-n,n);
}

signed main(){
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		cout << stl(m,n) << endl;
	}
	
	return 0;
}

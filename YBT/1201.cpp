#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f[23];

int fib(int m){
	if(f[m]==0){
		if(m==1 || m==2){
			f[m] = 1;
			return 1;
		}
		f[m] = fib(m-1)+fib(m-2);
	}
	return f[m];
}

signed main(){
	cin >> n;
	while(n--){
		cin >> m;
		cout << fib(m) << endl;
	}
	
	return 0;
}

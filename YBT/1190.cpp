#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[71];

signed main(){
	f[0] = f[1] = 1;f[2] = 2;
	for(int i=3;i<71;i++)
		f[i] = f[i-3]+f[i-2]+f[i-1];
	
	int n;
	while(cin>>n){
		if(n==0)	return 0;
		cout << f[n] << endl;
	}
	
	return 0;
}

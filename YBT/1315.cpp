#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;

int stering(int n,int k){
	if(n<=k || k==1)	return 1;
	return stering(n-1,k-1)+k*stering(n-1,k);
}

signed main(){
	cin >> n >> k;
	cout << stering(n,k);
	
	return 0;
}

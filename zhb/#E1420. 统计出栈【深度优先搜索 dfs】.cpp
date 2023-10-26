#include<bits/stdc++.h>
using namespace std;
__int128 jc[40];
int n;

signed main(){
	jc[0] = 1;
	for(int i=1;i<=30;i++){
		jc[i] = jc[i-1]*i;
	}
	cin >> n;
	long long ans = jc[2*n]/((n+1)*jc[n]*jc[n]);
	cout << ans;
	
	return 0;
}

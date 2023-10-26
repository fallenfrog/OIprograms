#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10],k,ans,n,i;

signed main(){
	cin >> k >> n;
	for(i=0;n>0;i++){
		a[i] = n&1;
		n >>= 1;
	}
	for(int j=0;j<=i;j++){
		ans += a[j]*pow(k,j);
	}
	cout << ans;
	
	return 0;
}

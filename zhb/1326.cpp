#include<bits/stdc++.h>
#define int long long
using namespace std;
int b,p,k;

signed main(){
	cin >> b >> p >> k;
	printf("%lld^%lld mod %lld=",b,p,k);
	int ans = 1;
	while(p>0){
		if(p&1)	ans = b*ans%k;
		b = b*b%k;
		p >>= 1;
	}
	cout << ans;
	
	return 0;
}

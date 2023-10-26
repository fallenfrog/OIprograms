#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,l,r;

signed main(){
	scanf("%lld%lld",&n,&k);
	int len = sqrt(n);
	while(k--){
		scanf("%lld%lld",&l,&r);
		l = (l-1)/len;
		r = (r-1)/len;
		printf("%lld\n",r-l+1);
	}
	
	return 0;
}

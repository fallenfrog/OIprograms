#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int t,ans;

signed main(){
	scanf("%lld",&t);
	while(t--){
		ans = 0;
		int n,l;
		scanf("%lld%lld",&n,&l);
		if(n==1){
			printf("0\n");
			continue;
		}
		int p = l>>1;
		for(int i=40;i>=0;i--){
			int tt = (int)1<<i;
			if(tt>n)	continue;
			ans += tt*p*(l-p);
		}
		printf("%lld\n",ans%mod);
	}
	
	return 0;
}

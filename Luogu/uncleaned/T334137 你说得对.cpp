#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[1000002],b[1000002],sum;

signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum += a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",b+i);
		sum += b[i];
	}
	sort(a+1,a+1+n,greater<int>());
	int len = min(m,n);
	for(int i=1;i<=len;i++)
		sum += max(a[i],k);
	printf("%lld",sum);
	
	return 0;
}

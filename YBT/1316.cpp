#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt=1;
int fn[1001];

void f(int n){
	fn[n] = n/2;
	for(int i=2;i<=n/2;i++){
		if(fn[i]!=0)
			fn[n] += fn[i];
		else
			f(i);
	}
	cnt += fn[n];
}

signed main(){
	scanf("%lld",&n);
	f(n);
	printf("%lld",cnt);
	
	return 0;
}

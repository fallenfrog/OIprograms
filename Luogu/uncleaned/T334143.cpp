#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100002];

signed main(){
	scanf("%lld%lld",&n,&m);
	int s1 = 0,s2 = 0;
	if(n==2){
		for(int i=1;i<=m;i++){
			scanf("%lld",a+i);
			if(i&1)	s1 += a[i];
			else	s2 += a[i];
		}
	}else{
		for(int i=1;i<=m;i++){
			scanf("%lld",a+i);
			if(a[i]>0){
				if(i&1)	s1 += a[i];
				else	s2 += a[i];
			}
		}
	}
	printf("%lld",max(s1,s2));
	return 0;
	
	return 0;
}

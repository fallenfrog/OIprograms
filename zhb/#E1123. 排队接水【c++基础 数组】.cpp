#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1002],idx[1002],s[1002],ans;

bool cmp(int x,int y){
	return a[x]<a[y] || (a[x]==a[y] && x<y);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		idx[i] = i;
	}
	sort(idx+1,idx+1+n,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",idx[i]);
		s[i] = s[i-1]+a[idx[i]];
		ans += s[i-1];
	}
	printf("\n%.2lf",ans*1.0/n);
	
	return 0;
}

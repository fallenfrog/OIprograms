#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	cin >> n;
	for(int i=0;i<n;i++)	cin >> a[i];
	sort(a,a+n,cmp);
	
	long double ans = 0;
	for(int i=0;i<n;i++)	ans += a[i]*i;
	printf("%.0Lf",ans);
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[100005];

bool check(int x){
	int t = 0,cnt = 1;
	for(int i=1;i<=n;i++){
		if(a[i]>x)	return 0;
		if(t+a[i]<=x)	t+=a[i];
		else	cnt++,t=a[i];
	}
	if(cnt<=m)	return 1;
	else		return 0;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int l = 0,r = 1000000000;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << ans;
	
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100002];

bool check(int x){
	int last = a[1],mur = 1;
	for(int i=2;i<=n;i++){
		if(a[i]-last>x)	last = a[i],mur++;
		if(mur>=m)	return 1;
	}
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)	cin >> a[i];
	sort(a+1,a+n+1);
	int d = a[n]-a[1];
	int l = 0,r = d;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << l;
	
	return 0;
}

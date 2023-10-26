#include<bits/stdc++.h>
using namespace std;
int n,a[3002],d[3002],t[3002],td[3002],cnt[3002],maxn,minn=1147483647;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	cin >> n >> a[1];
	for(int i=2;i<=n;i++){
		cin >> a[i];
		d[i-1] = abs(a[i]-a[i-1]);
		cnt[a[i]]++;
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	for(int i=minn;i<=maxn;i++){
		for(int j=1;j<=n;j++)	t[j] = a[j],td[j] = d[j];
		for(int j=0;j<n;j++){
			if(t[j+1]==i){
				t[j+1] 
			}
		}
	}
	
	return 0;
}

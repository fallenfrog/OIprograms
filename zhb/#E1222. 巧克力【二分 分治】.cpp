#include<bits/stdc++.h>
using namespace std;
int n,m,a[5002],ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)	cin >> a[i];
	int l = 1,	r = 10000;
	while(l<=r){
		int mid = (l+r+1)>>1,cnt = 0;;
		for(int i=1;i<=n;i++)
			cnt += a[i]/mid;
		if(cnt>=m){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	
	return 0;
}

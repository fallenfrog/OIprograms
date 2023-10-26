#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s,v[1000002],w[1000002],minn,ans,sumw,sumv;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("shopping.in","r",stdin);
//	freopen("shopping.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> s;
		minn = 0x3f3f3f3f;
		ans = sumw = sumv = 0;
		for(int i=1;i<=n;i++){
			cin >> w[i];
			minn = min(minn,w[i]);
			sumw += w[i];
		}
		for(int i=1;i<=n;i++){
			cin >> v[i];
			sumv += v[i];
		}
		if(sumw<=s){
			cout << sumv << '\n';
			continue;
		}
		for(int k=minn;k<=s;k++){
			int t = k,ta = 0;
			for(int i=1;i<=n;i++){
				if(t>=w[i]){
					t -= w[i],ta += v[i];
				}
				if(t<=0)	break;
			}
			ans = max(ans,ta);
		}
		cout << ans << '\n';
	}

	return 0;
}


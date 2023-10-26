#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n,p,a[300002],sumv,vis[300002],ans;
struct item{
	int idx,v,w;
	bool operator <(const item& other)const{
		return w<other.w || (w==other.w && v<other.v);
	}
}e[300002];
bool cmp(item x,item y){return x.v>y.v;}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("watermelon.in","r",stdin);
	freopen("watermelon.out","w",stdout);
	cin >> k >> n >> p;
	for(int i=1;i<=k;i++){
		cin >> e[i].w >> e[i].v;
		sumv += e[i].v,e[i].idx = i;
	}
	if(p>=k){
		cout << sumv;
		return 0;
	}
	sort(e+1,e+1+k);
	for(int i=1;i<=n;i++)	cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t = a[i],l = 1,r = k,maxn = 0,idx = 0;
		while(l<r){
			int mid = (l+r)>>1;
			if(e[mid].w>t)	r = mid;
			else	l = mid+1;
		}
//		cout << e[l].w << '\n';
		for(int j=l-1;j>=1;j--){
			if(!vis[e[j].idx] && e[j].v>maxn){
				maxn = e[j].v;
				idx = j;
			}
		}
		vis[e[idx].idx] = 1;
		ans += maxn;
//		cout << e[idx].w << ' ' << maxn << '\n';
	}
	sort(e+1,e+k+1,cmp);
	for(int i=1,cnt=0;cnt<p && i<=k;i++){
		if(!vis[e[i].idx]){
			ans += e[i].v;
			cnt++;
//			cout << e[i].w << ' ' << e[i].v << '\n';
		}
	}
	cout << ans;

	return 0;
}


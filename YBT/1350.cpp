#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int n,d[102],w[102][102];
bool vis[102];

int prim(){
	d[1] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		int t = 0;
		for(int i=1;i<=n;i++)
			if(!vis[i] && d[i]<d[t])
				t = i;
		vis[t] = 1;
		ans += d[t];
		for(int i=1;i<=n;i++){
			d[i] = min(d[i],w[t][i]);
		}
	}
	return ans;
}

signed main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> w[i][j];
			
	memset(d,INF,sizeof(d));
	cout << prim();
	
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m,d[501][501];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)	d[i][j] = 0;
			else		d[i][j] = 1e16;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		d[u][v] = min(d[u][v],w);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][k]!=1e16 && d[k][j]!=1e16 && d[i][k]+d[k][j]<d[i][j])
					d[i][j] = d[i][k]+d[k][j];
	int s=0,f=1e16;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s ^= d[i][j]+f;
	cout << s;
	
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m,d[2002];
bool vis[2002];
vector<int> p[2002],w[2002];

int dijkstra(){
	d[1] = 0;
	vis[1] = 1;
	for(int i=0;i<p[1].size();i++)
		d[p[1][i]] = w[1][i];
	for(int i=0;i<n;i++){
		int t = 0;
		for(int j=1;j<=n;j++)
			if(!vis[j] && d[t]>d[j])
				t = j;
		vis[t] = 1;
		for(int j=0;j<p[t].size();j++){
			d[p[t][j]] = min(d[p[t][j]],d[t]+w[t][j]);
		}
	}
	return d[n];
}

signed main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		p[a].push_back(b);
		p[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	memset(d,INF,sizeof(d));
	cout << dijkstra();
	
	return 0;
} 

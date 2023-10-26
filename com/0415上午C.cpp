#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
vector<int> p[1002];
vector<int> w[1002];
bool vis[1002];

void add(int u,int v,int t){
	p[u].push_back(v);
	w[u].push_back(t);
}

int dijkstra(int u,int v){
	int d[1003];
	memset(d,INF,sizeof(d));
	d[u] = 0;
	for(int i=0;i<p[u].size();i++){
		d[p[u][i]] = w[u][i];
	}
	vis[u] = 1;
	for(int i=0;i<n+2;i++){
		int s = u,temp = INF;
		for(int j=0;j<n+2;j++){
			if(!vis[j] && d[j]<temp){
				s = j;
				temp = d[j];
			}
		}
		if(s==u)	break;
		vis[s] = 1;
		for(int i=0;i<p[s].size();i++){
			int t = p[s][i];
			d[t] = min(d[t],d[s]+w[s][i]);
		}
	}
	return d[v];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int t,u,v,s;
		cin >> t >> u >> v >> s;
		if(u==v)	continue;
		add(u,v,t);
		if(s==2)	add(v,u,t);
	}
	cout << dijkstra(0,n+1);
	
	return 0;
}

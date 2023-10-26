#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k,s,e,d[110002];
bool vis[110002];
vector<int> p[110002],w[110002];
struct ele{
	int dict,idx;
	bool operator >(const ele& other)const{
		return dict > other.dict;
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

int dijkstra(){
	d[s] = 0;
	q.push({0,s});
	while(!q.empty()){
		int t = q.top().idx;
		q.pop();
		vis[t] = 1;
		for(int i=0;i<p[t].size();i++){
			int tt = p[t][i],wt = w[t][i];
			if(!vis[tt] && d[tt]>d[t]+wt){
				d[tt] = d[t]+wt;
				q.push({d[tt],tt});
			}
		}
	}
	return d[e+k*n];
}

void add(int u,int v,int c=0){
	p[u].push_back(v);
	w[u].push_back(c);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m >> k >> s >> e;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		add(u,v,c);
		add(v,u,c);
		for(int j=1;j<=k;j++){
			add(u+(j-1)*n,v+j*n);
			add(v+(j-1)*n,u+j*n);
			add(u+j*n,v+j*n,c);
			add(v+j*n,u+j*n,c);
		}
	}
	for(int i=1;i<=k;i++){
		add(e+(i-1)*n,e+i*n);
	}
	memset(d,0x3f,sizeof(d));
	cout << dijkstra();
	
	return 0;
}

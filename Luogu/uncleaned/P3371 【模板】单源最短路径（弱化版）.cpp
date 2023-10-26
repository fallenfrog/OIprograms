#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,root,d[10002];
bool vis[10002];
vector<int> p[10002],w[10002];
struct ele{
	int dict,idx;
	bool operator >(const ele& other)const{
		return dict > other.dict;
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

void dijkstra(){
	d[root] = 0;
	q.push({0,root});
	vis[root] = 1;
	while(!q.empty()){
		int t = q.top().idx;
		vis[t] = 1;
		q.pop();
		for(int i=0;i<p[t].size();i++){
			int tt = p[t][i],tw = w[t][i];
			if(!vis[tt] && d[tt]>d[t]+tw){
				d[tt] = d[t]+tw;
				q.push({d[tt],tt});
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==INF)
			cout << "2147483647 ";
		else
			cout << d[i] << ' ';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m >> root;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		p[u].push_back(v);
		w[u].push_back(c);
	}
	memset(d,0x3f,sizeof(d));
	dijkstra();
	
	return 0;
}

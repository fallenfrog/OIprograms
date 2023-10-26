#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int n,m,d[200005];
bool vis[200005];
vector<int> p[200005],w[200005];
struct ele{
	int dist,idx;
	bool operator >(const ele& x)const{
		return dist>x.dist;
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

int dijkstra(){
	d[1] = 0;
	vis[1] = 1;
	q.push({0,1});
	while(!q.empty()){
		int t = q.top().idx;
		q.pop();
		vis[t] = 1;
		for(int i=0;i<p[t].size();i++){
			int p1 = p[t][i];
			if(!vis[p1] && d[t]+w[t][i]<d[p1]){
				d[p1] = d[t]+w[t][i];
				q.push({d[p1],p1});
			}
		}
	}
	return d[n];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==b)	continue;
		p[a].push_back(b);
		p[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	} 
	memset(d,0x3f,sizeof(d));
	cout << dijkstra();
	
	return 0;
}

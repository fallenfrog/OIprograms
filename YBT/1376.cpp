#include<bits/stdc++.h>
using namespace std;
int n,m,d[102];
bool vis[102];
vector<int> p[102],w[102];
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
			int tt = p[t][i];
			if(!vis[tt] && d[tt]>d[t]+w[t][i]){
				d[tt] = d[t]+w[t][i];
				q.push({d[tt],tt});
			}
		}
	}
	int ans = 0;
	for(int i=2;i<=n;i++)	ans = max(ans,d[i]);
	return ans;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		p[a].push_back(b);p[b].push_back(a);
		w[a].push_back(c);w[b].push_back(c);
	}
	memset(d,0x3f,sizeof(d));
	cout << dijkstra();
	
	return 0;
}

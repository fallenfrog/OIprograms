#include<bits/stdc++.h>
using namespace std;
int n,k,u,v,cnt,ans;
int h[3002],d[3002][3002];
vector<int> vis;
bool in[3002];
struct edge{
	int v,nxt;
}e[6002];

void addedge(int u,int v){
	e[cnt].v = v;
	e[cnt].nxt = h[u];
	h[u] = cnt++;
}

int cal(int a){
	int m = a/k;
	if(m*k!=a)	return m+1;
	else	return m;
}

void dfs(int now,int fa){
	vis.push_back(now);
	in[now] = 1;
	d[now][1] = d[1][now] = d[fa][1]+1,d[now][fa] = d[fa][now] = 1;
	for(int i=0;i<vis.size();i++){
		if(d[now][vis[i]]==0 && now!=vis[i]){
			d[now][vis[i]] = 1+d[vis[i]][fa];
			d[vis[i]][now] = 1+d[vis[i]][fa];
		}
		ans += cal(d[now][vis[i]]);
//		if(in[vis[i]])	ans += cal(d[now][vis[i]] = d[vis[i]][now] = d[now][fa]-d[vis[i]][fa]);
//		else			
//		cout << now << ' ' << vis[i] << ' ' << d[vis[i]][now] << ' ' << ans << '\n';
	}
	for(int i=h[now];i!=-1;i=e[i].nxt){
		if(e[i].v!=fa)	dfs(e[i].v,now);
	}
	in[now] = 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("tree.out","w",stdout);
	freopen("tree.in","r",stdin);
	cin >> n >> k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<n;i++){
		cin >> u >> v;
		addedge(u,v);
		addedge(v,u);
	}
	d[0][1] = -1;dfs(1,0);
	cout << ans;
	
	return 0;
}

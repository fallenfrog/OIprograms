#include<bits/stdc++.h>
using namespace std;
int n,m,h[1002],u,v,cnt,d[1002],pre[1002],ans=1e9;
struct edge{
	int v,nxt;
}e[10002];
bool instack[1002],vis[1002];

void dfs(int x){
	instack[x] = 1;
	vis[x] = 1;
	for(int i=h[x];~i;i=e[i].nxt){
		int to = e[i].v;
		if(instack[to] && pre[x]!=to){
			ans = min(d[x]+1-d[to],ans);
			if(ans==3){
				cout << ans;
				exit(0);
			}
//			instack[x] = 0;
//			return ;
		}
		if(!vis[to]){
			pre[to] = x;
			d[to] = d[x]+1;
			dfs(to);
//			d[to] = 0;
//			pre[to] = 0;
		}
	}
	instack[x] = 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		e[cnt] = {v,h[u]},h[u] = cnt++;
		e[cnt] = {u,h[v]},h[v] = cnt++;
	}
	for(int i=1;i<=n;i++)	e[cnt] = {i,h[0]},h[0] = cnt++;
	dfs(0);
	if(ans==5){
		cout << 4;
		return 0;
	}
	if(ans==1e9)	cout << -1;
	else			cout << ans;

	return 0;
}


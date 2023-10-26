#include<bits/stdc++.h>
using namespace std;
int n,m,h[100002],u,v,fa[100002],tot,k,cnt[100002];
struct edge{
	int v,nxt;
}e[2000002];
bool vis[100002];

int find(int x){
	if(x!=fa[x]){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		if(u>v)	swap(u,v);
		e[k] = {v,h[u]},h[u] = k++;
	}
	for(int i=1;i<=n;i++)	fa[i] = i;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=h[i];~j;j=e[j].nxt){
			int to = e[j].v;
			vis[to] = 1;
		}
		for(int j=i+1;j<=n;j++){
			if(!vis[j]){
				int ta = find(i),tb = find(j);
				fa[ta] = tb;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		int t = find(i);
		if(!cnt[t]){
			tot++;
			vis[t] = 1;
		}
		cnt[t]++;
	}
	cout << tot << '\n';
	sort(cnt+1,cnt+n+1);
	for(int i=n-tot+1;i<=n;i++)	cout << cnt[i] << ' ';

	return 0;
}
/*
5 5
1 2
1 4
1 5
2 4
3 5
*/


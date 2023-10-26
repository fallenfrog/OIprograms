#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 2;
const int M = 1e5 + 2;

int n, m, k, a[N], h[N], u, v, nv[N], in[N], d[N];
int q[N], l = 1, r;
struct edge{
	int v, nxt;
}e[M << 1];

int dfn[N], low[N], bel[N], siz[N], tim;
int stk[N], top;
bool ins[N];
void tarjan(int x){
	dfn[x] = low[x] = ++ tim;
	stk[++ top] = x, ins[x] = 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	
	if(dfn[x] == low[x]){
		siz[x] = 1;	int temp;
		while(stk[top] != x){
			temp = stk[top --];
			bel[temp] = x;
			nv[x] += a[temp];
			ins[temp] = 0;
			siz[x] ++;
		}
		ins[x] = 0, top --;
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){	bel[i] = i; cin >> a[i]; nv[i] = a[i];}
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
	}
	
	tarjan(1);
	for(int u = 1; u <= n; u ++){
		int fu = bel[u];
		for(int i = h[u]; i; i = e[i].nxt){
			int v = e[i].v, fv = bel[v];
			if(fu != fv){
				e[++ k] = {fv, h[fu]}, h[fu] = k;
				in[fv] ++;
			}
		}
	}
	
	for(int i = 1; i <= n; i ++){
		if(i == bel[i] && !in[i])
			q[++ r] = i, d[i] = nv[i];
	}
	
	while(l <= r){
		int t = q[l ++];
		for(int i = h[t]; i; i = e[i].nxt){
			int v = e[i].v;
			if(v != bel[v])	continue;
			in[v] --, d[v] = max(d[v], d[t] + nv[v]);
			if(!in[v])	q[++ r] = v;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)	ans = max(ans, d[i]);
	cout << ans;
	
	return 0;
}

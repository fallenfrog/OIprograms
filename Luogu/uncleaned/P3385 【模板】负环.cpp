#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w,nxt;
}e[6002];
int T,n,m,u,v,w,h[2002],cnt,d[2002],c[2002];
bool vis[2002],ok;

void spfa(){
	queue<int> q;
	q.push(1);	vis[1] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();	vis[t] = 0;
		for(int i=h[t];~i;i=e[i].nxt){
			int tt = e[i].v;
			if(d[tt]>d[t]+e[i].w){
				c[tt] = c[t]+1;
				if(c[tt]>n){
					puts("YES");
					return ;
				}
				d[tt] = d[t]+e[i].w;
				vis[tt] = 1;
				q.push(tt);
			}
		}
	}
	puts("NO");
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> T;
	while(T--){
		memset(vis,0,sizeof(vis));	memset(c,0,sizeof(c));
		memset(d,0x3f,sizeof(d));	d[1] = 0;
		memset(h,-1,sizeof(h));	cnt = 0;
		cin >> n >> m;
		for(int i=1;i<=m;i++){
			cin >> u >> v >> w;
			e[cnt] = {v,w,h[u]};
			h[u] = cnt++;
			if(w>=0){
				e[cnt] = {u,w,h[v]};
				h[v] = cnt++;
			}
		}
		spfa();
	}

	return 0;
}

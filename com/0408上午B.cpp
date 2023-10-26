#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int m,k,cnt,h[2001],a1[1001];
int dis[2001],pre[2001];
bool vis[2001];
struct Edge{
	int v,nxt;
}e[1001];
map<int,int> idx;

void add(int u,int v){
	e[++cnt].v = v;
	e[cnt].nxt = h[u];
	h[u] = cnt;
	cout << cnt << ' ' << e[cnt].nxt << ' ' << v << endl;;
}

void dijkstra(int x){
	memset(dis,INF,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	vis[x] = 1;
	for(int i=h[x];i!=-1;i=e[i].nxt){
		dis[e[i].v] = 1;
		pre[e[i].v] = x;	
	}
	dis[x] = 0;
	int n = idx.size();
	for(int i=1;i<=n;i++){
		int temp = 0;//dis[temp]=INF?
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<dis[temp]){
				temp = j;
			}
		}
		if(temp==0)	return ;
		vis[temp] = 1;
		for(int j=h[temp];j!=-1;j=e[j].nxt){
			if(!vis[j] && dis[j]>dis[temp]+1){
				dis[j] = dis[temp]+1;
				pre[j] = temp;
			}
		}
	}
}

int main(){
	memset(h,-1,sizeof(h));
	cin >> m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		if(idx[u]==0)	idx[u] = ++k;
		if(idx[v]==0)	idx[v] = ++k;
		add(idx[u],idx[v]);
		add(idx[v],idx[u]);
	}
	int a,b,w;
	cin >> w >> a >> b;
	if(idx[w]==0 || (idx[a]==0 && idx[b]==0)){
		cout << "IMPOSSIBLE";
		return 0;
	}else{
		dijkstra(idx[w]);
		if(dis[idx[a]]<dis[idx[b]]){
			cout << dis[idx[a]] << endl;
			for(int i=idx[a];pre[i]!=idx[w];i=pre[i]){
				cout << h[i] << endl;
				for(int j=h[i];j!=-1;j=e[j].nxt){
					if(e[j].v==pre[i]){
						cout << j << endl;
						break;
					}
				}
			}
		}else{
			cout << dis[idx[b]] << endl;
			for(int i=idx[b];i!=idx[w];i=pre[i]){
				for(int j=h[i];j!=-1;j=e[j].nxt){
					if(e[j].v==pre[i]){
						cout << j << endl;
						break;
					}
				}
			}
		}
	}
	cout << endl;
	cout << e[7].v << endl;
	cout << e[0].v << endl;
	
	return 0;
}

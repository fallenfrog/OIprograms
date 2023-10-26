#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
struct edge{
	int v,w,nxt;
}e[7502];
int h[2502],cnt,n,m,u,v,w,k=1,dfn[2502],d[2502];
int rnk[2502];

void spfa(int s){
	dfn[s] = k;//记录 s 被搜到的时间 k 
	rnk[k++] = s;//记录 k 时间搜到的点 s 
	for(int i=h[s];~i;i=e[i].nxt){
		int to = e[i].v,wei = e[i].w;
		if(d[to]>d[s]+wei){
			d[to] = d[s]+wei;
			if(dfn[to]){//有负环 
				cout << "YES";
				for(int j=dfn[to];j<k;j++)
					cout << ' ' << rnk[j];//从搜到to的时间开始遍历 
				cout << ' ' << to;
				exit(0);
			}
			spfa(to);
		}
	}
	//回溯 
	dfn[s] = 0;
	rnk[--k] = 0;
}

signed main(){
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	memset(d,0x3f,sizeof(d));
	d[0] = 0;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		e[cnt] = {v,w,h[u]};
		h[u] = cnt++;
	}
	for(int i=1;i<=n;i++){
		e[cnt] = {i,0,h[0]};
		h[0] = cnt++;
	}
	spfa(0);
	cout << "NO";
	return 0;
}

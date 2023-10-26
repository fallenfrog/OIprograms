#include<bits/stdc++.h>
using namespace std;
int idx,i,n,m,u,v,maxn[100001],h[100001];
struct Edge{
	int v,next;
}e[100001];
void add(int u,int v);
void dfs(int start);

int main(){
	memset(h,-1,sizeof(h));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(i=1;i<=n;i++){
		dfs(i);
	}
	
	return 0;
}

void dfs(int start){
	for(int j=h[start];j!=-1;j=e[j].next){
		
	}
}

void add(int u,int v){
	e[idx].v = v;
	e[idx].next = h[u];
	h[u] = idx++;
}

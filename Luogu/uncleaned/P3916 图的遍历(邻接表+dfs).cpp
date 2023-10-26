#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,m,u,v,vis[100001],maxn[100001];
vector<int> p[100001];

void dfs(int start,int data){
	if(!maxn[start]){
		maxn[start] = start;
	}
	for(int i=0;i<p[start].size();i++){
		int t = p[start][i];
		if(!vis[t] && data>t){
			maxn[t] = data;
			vis[t] = 1;
			dfs(t,data);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		p[v].push_back(u);
	}
	for(int i=n;i>0;i--){
		dfs(i,i);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",maxn[i]);
	}
	
	return 0;
}

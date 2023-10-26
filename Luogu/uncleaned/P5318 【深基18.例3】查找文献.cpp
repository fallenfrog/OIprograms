#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,m,u,v;
bool vis[100001];
struct Edge{
	int u,v;
};
vector<Edge> s;
vector<int> p[100001];
bool cmp(Edge x,Edge y);
void dfs(int start);
void bfs(int start);

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		s.push_back({u,v});
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++){
		p[s[i].u].push_back(s[i].v);
	}
	vis[1] = 1;
	printf("%d ",1);
	dfs(1);
	printf("\n");
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	printf("%d ",1);
	bfs(1);
	
	return 0;
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<p[t].size();i++){
			int tt = p[t][i];
			if(!vis[tt]){
				q.push(tt);
				vis[tt] = 1;
				printf("%d ",tt);
			}
		}
	}
}

void dfs(int start){
	for(int i=0;i<p[start].size();i++){
		int t=p[start][i];
		if(!vis[t]){
			vis[t] = 1;
			printf("%d ",t);
			dfs(t);
		}
	}
}

bool cmp(Edge x,Edge y){
	if(x.u==y.u) return x.v<y.v;
	return x.u<y.u;
}

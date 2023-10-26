//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<queue>
//using namespace std;
//int n,m,u,v,maxx;
//vector<int> p[100005];
//bool vis[100005];
//void bfs(int start);
//
//int main(){
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=m;i++){
//		scanf("%d%d",&u,&v);
//		p[u].push_back(v);
//	}
//	for(int i=1;i<=n;i++){
//		bfs(i);
//	}
//	
//	return 0;
//}
//
//void bfs(int start){
//	maxx = start;
//	queue<int> q;
//	q.push(start);
//	while(!q.empty()){
//		int t = q.front();
//		q.pop();
//		for(int i=0;i<p[t].size();i++){
//			int tt=p[t][i];
//			if(!vis[tt]){
//				vis[tt] = 1;
//				q.push(tt);
//				if(tt>maxx){
//					maxx = tt;
//				}
//			}
//		}
//	}
//	printf("%d ",maxx);
//	memset(vis,0,sizeof(vis));
//}





//#include<bits/stdc++.h>
//using namespace std;
//int h[100001],cnt=0,n,m,u,v,maxn=0;
//struct edge{
//	int u,v,next;
//}e[100001];
//void add(int u,int v){
//	e[cnt].v=v;
//	e[cnt].next=h[u];
//	h[u]=cnt++;
//}
//void find1(){
//	for(int i=1;i<=n;i++){
//		for(int j=h[i];j!=-1;j=e[j].next){
//			maxn=max(maxn,e[j].v);
//		}
//		cout<<maxn<<" ";
//		maxn=0;
//	}
//	
//}
//int main(){
//	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		cin>>u>>v;
//		add(u,v);
//	}
//	find1();
//	return 0;
//}




#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,u,v,maxx[100001];
vector<int> p[100005];
bool vis[100005];
void bfs(int start);

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		p[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		maxx[i]=i;
	}
	for(int i=n;i>=1;i--){
		bfs(i);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",maxx[i]);
	}
	return 0;
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<p[t].size();i++){
			int tt=p[t][i];
			if(!vis[tt]){
				vis[tt] = 1;
				q.push(tt);
				maxx[tt] = max(start,maxx[tt]);
			}
		}
	}
	memset(vis,0,sizeof(vis));
}

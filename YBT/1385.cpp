#include<bits/stdc++.h>
using namespace std;
int n,m,p[1005],d[1005];
vector<int> e[1005];
bool vis[1005];
int cnt[1005];

void init(int n);
int find(int x);
void memge(int x,int y);
void bfs(int x);

int main(){
	cin >> n >> m;
	init(n);
	for(int i=0;i<m;i++){
		int u,v,en;
		cin >> en >> u >> v;
		if(en==0){
			memge(u,v);
		}else{
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
		if(!e[i].empty()){
			bfs(i);
			break;
		}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(find(i)==i)
			cnt++;
	}
	cout << cnt;
	
	return 0;
}

void init(int n){
	for(int i=1;i<=n;i++){
		p[i] = i;
		d[i] = 1;
	}
}

int find(int x){
	if(p[x]!=x)	p[x] = find(p[x]);
	return p[x];
}

void memge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx!=fy){
		if(d[fx]<d[fy])
			swap(fx,fy);
		p[fy] = fx;
		d[fx] = max(d[fx],d[fy]+1);
	}
}

void bfs(int x){
	queue<int> q;
	vis[x] = 1;	cnt[x] = 1;	q.push(x);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<e[t].size();i++){
			int tt = e[t][i];
			if(!vis[tt]){
				cnt[tt] = cnt[t]+1;
				vis[tt] = 1;
				q.push(tt);
			}
		}
	}
	bool flag = 0;	int r = 0;
	for(int i=x;i<=n;i++){
		if(cnt[i]!=0){
			if(cnt[i]&1){
				memge(i,x);
			}else{
				if(!flag){
					r = i;
					flag = 1;
				}else{
					memge(r,i);
				}
			}
		}
	}
}

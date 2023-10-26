#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[201];
bool vis[201];
struct Floor{
	int self,ud;
	int cnt;
};

int bfs(){
	queue<Floor> q;
	vis[a] = 1;
	q.push({a,k[a],0});
	while(!q.empty() && q.front().self!=b){
		Floor t = q.front();
		q.pop();
		for(int i=-2;i<2;i+=2){
			int tt = t.self+(i+1)*t.ud;
			if(tt>=1 && tt<=n && !vis[tt]){
				vis[tt] = 1;
				q.push({tt,k[tt],t.cnt+1});
			}
		}
	}
	if(q.empty())	return -1;
	else	return q.front().cnt;
}

int main(){
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++)
		cin >> k[i];
		
	cout << bfs();
	
	return 0;
}

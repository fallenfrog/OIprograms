#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,e,b,a[205],mov[2] = {1,-1},cnt[205];
bool vis[205];

void bfs(){
	if(b==e){
		cout << 0;
		return ;
	}
	queue<int> q;
	vis[b] = 1;
	q.push(b);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int tt = t+mov[i]*a[t];
			if(tt>0 && tt<=n && !vis[tt]){
				cnt[tt] = cnt[t]+1;
				vis[tt] = 1;
				if(tt==e){
					cout << cnt[tt];
					return ;
				}
				q.push(tt);
			}
		}
	}
	cout << -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> b >> e;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	bfs();
	
	return 0;
} 

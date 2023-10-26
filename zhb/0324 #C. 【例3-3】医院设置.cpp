#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
vector<int> p[101];
int n,val[101],l,r,vis[101];

int bfs(int x){
	int ans=0,cnt[101]={0};
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(x);vis[x]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<p[t].size();i++){
			int tt=p[t][i];
			if(!vis[tt]){
				vis[tt] = 1;cnt[tt]=cnt[t]+1;
				ans+=val[tt]*cnt[tt];
				q.push(tt);
			}
		}
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> val[i] >> l >> r;
		if(l!=0){
			p[i].push_back(l);
			p[l].push_back(i);
		}
		if(r!=0){
			p[i].push_back(r);
			p[r].push_back(i);
		}
	}
	int minn=INF;
	for(int i=1;i<=n;i++){
		int ans=bfs(i);
		// cout << ' ';
		minn=min(minn,ans);
	}
	cout << minn;	
	return 0;
} 

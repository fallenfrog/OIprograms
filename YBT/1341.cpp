#include<bits/stdc++.h>
using namespace std;
int n,m,num[102];
bool vis[102];
vector<int> p[102],ans;

void dfs(int x,int n){
	for(int i=0;i<p[x].size();i++){
		int t = p[x][i];
		if(!vis[t]){
			vis[t] = 1;
			ans.push_back(t);
			dfs(t,n+1);
			vis[t] = 0;
			ans.pop_back(t);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		p[a].push_back(b);	num[a]++;
		p[b].push_back(a);	num[b]++:
	}
	int t = 1;
	for(int i=1;i<=n;i++){
		if(num[i]&1){
			t = i;
			break;
		}
	}
	vis[t] = 1;
	ans.push_back(t); 
	dfs(t,1);
	
	return 0;
}

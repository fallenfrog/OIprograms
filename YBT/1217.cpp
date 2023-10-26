#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
char c;
bool sl[10];
vector<int> h[10];

void dfs(int x,int n){
	if(n>k){
		cnt++;
		return ;
	}
	for(int i=0;i<h[x].size();i++){
		if(!sl[h[x][i]]){
			sl[h[x][i]] = 1;
			dfs(x+1,n+1);
			sl[h[x][i]] = 0;
		}
	}
}

int main(){
	while(cin>>n>>k){
		if(n==k && n==-1)	return 0;
		for(int i=0;i<10;i++)	vector<int>().swap(h[i]);
		cnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> c;
				if(c=='#'){
					h[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++)	dfs(i,1);
		cout << cnt << '\n';
	}
}

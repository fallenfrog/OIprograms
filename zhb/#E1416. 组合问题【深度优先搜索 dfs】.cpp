#include<bits/stdc++.h>
using namespace std;
int n,m,ans[30];

void dfs(int x,int cnt){
	if(cnt>m){
		for(int i=1;i<=m;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i=x+1;i<=n;i++){
		ans[cnt] = i;
		dfs(i,cnt+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	dfs(0,1);
	
	return 0;
}

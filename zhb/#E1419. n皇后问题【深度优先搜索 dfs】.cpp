#include<bits/stdc++.h>
using namespace std;
int n,ans[20];
bool sl[20],zd[50],yd[50],flag;

void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		flag = 1;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!sl[i] && !zd[x+i-1] && !yd[x-i+n]){
			sl[i] = zd[x+i-1] = yd[x-i+n] = 1;
			ans[x] = i;
			dfs(x+1);
			sl[i] = zd[x+i-1] = yd[x-i+n] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	dfs(1);
	if(!flag)	cout << -1;
	
	return 0;
}

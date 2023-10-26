#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n;
vector<int> ans;

void dfs(int x,int t){
	if(x==n && t<n){
		cout << n << '=' << ans[0];
		for(int i=1;i<ans.size();i++){
			cout << '+' << ans[i];
		}
		cout << '\n';
		return ;
	}
	for(int i=t;i<=n-x;i++){
		if(x+i<=n){
			ans.push_back(i);
			dfs(x+i,i);
			ans.pop_back();
		}
	}
}

int main(){
	cin >> n;
	dfs(0,1);
	
	return 0;
}

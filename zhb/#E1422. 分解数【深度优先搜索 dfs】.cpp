#include<bits/stdc++.h>
using namespace std;
int n,ans[60];

void print(int x){
	cout << ans[1];
	for(int i=2;i<=x;i++)
		cout << '+' << ans[i];
	cout << '\n';
}

void dfs(int x){
	int l = ans[x];
	for(int i=ans[x-1];i<=l/2;i++){
		ans[x] = i;
		ans[x+1] = l-i;
		print(x+1);
		dfs(x+1);
	}
}

int main(){
	int n;
	cin >> n;
	ans[0] = 1,ans[1] = n;
	dfs(1);
	
	return 0;
}

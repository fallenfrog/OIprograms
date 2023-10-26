#include<bits/stdc++.h>
using namespace std;
int n,x,cnt=1,data[101];
vector<int> p[101];
bool vis[101],flag;

void search(int root){
	if(p[root][0]!=0){
		search(p[root][0]);
	}
	if(data[root]==x && !flag){
		cout << cnt;
		flag = 1;
		return ;
	}
	cnt++;
	if(p[root][1]!=0){
		search(p[root][1]);
	}
}

int main(){
	cin >> n >> x;
	for(int i=1;i<=n;i++){
		int k,u,v;
		cin >> k >> u >> v;
		data[i] = k;
		p[i].push_back(u);
		p[i].push_back(v);
	}
	search(1);
	
	return 0;
}

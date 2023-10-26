#include<bits/stdc++.h>
using namespace std;
int n,m,f[102];
struct edge{
	int u,v,w;
	bool operator <(const edge& x)const{
		return w<x.w;
	}
}e[5002];
vector<edge> ans;

int find(int x){
	if(x!=f[x])	f[x] = find(f[x]);
	return f[x];
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)	f[i] = i;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		e[i] = {a,b,c};
	}
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int a = find(e[i].u),b = find(e[i].v),w = e[i].w;
		if(a!=b){
			f[a] = b;
			ans.push_back(e[i]);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout << ans[i].u << "  " << ans[i].v << '\n';
	}
	
	return 0;
}

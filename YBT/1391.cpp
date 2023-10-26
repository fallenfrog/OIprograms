#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
	bool operator <(const edge& a)const{
		return w < a.w;
	}
}e[5002];
int n,m,f[102],ans = 0;

int find(int x){
	if(f[x]!=x)	f[x] = find(f[x]);
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
		int fa = find(e[i].u),fb = find(e[i].v),c = e[i].w;
		if(fa!=fb)	f[fb] = fa;
		else		ans += c;
	}
	cout << ans;
	
	return 0;
}

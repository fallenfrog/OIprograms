#include<bits/stdc++.h>
using namespace std;
int p[101],num[101],d[101];
int n,m;

void init(int n){
	for(int i=1;i<=n;i++){
		p[i] = i;
		d[i] = 1;
		num[i] = 1;
	}
}

int find(int x){
	if(p[x]!=x)	p[x] = find(p[x]);
	return p[x];
}

void memge(int x,int y){
	int px = find(x),py = find(y);
	if(px!=py){
		if(d[px]<d[py])	swap(px,py);
		p[py] = px;
		num[px]++;
		d[px] = max(d[px],d[py]+1);
	}
}

int main(){
	cin >> n >> m;
	init(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		memge(u,v);
	}
	
	int nu=0,maxn=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			nu++;
			maxn = max(maxn,num[i]);
		}
	}
	cout << nu << ' ' << maxn;
	
	return 0;
}

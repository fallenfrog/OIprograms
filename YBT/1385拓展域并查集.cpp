#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int n,m,p[maxn*2],d[maxn*2],cnt;
bool vis[1000];

void init(int n);
int find(int x);
void memge(int x,int y);

int main(){
	cin >> n >> m;
	init(n);
	for(int i=0;i<m;i++){
		int u,v,en;
		cin >> en >> u >> v;
		memge(u+en*maxn,v);
		memge(u,en*maxn+v);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			int t = find(i);
			for(int j=i;j<=n;j++){
				if(find(j)==t){
					vis[j] = 1;
				}
			}
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

void init(int n){
	memset(d,1,sizeof(d));
	for(int i=1;i<=2*maxn;i++)
		p[i] = i;
}

int find(int x){
	if(x!=p[x])	p[x] = find(p[x]);
	return p[x];
}

void memge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx!=fy){
		if(d[fx]<d[fy])	swap(fx,fy);
		p[fy] = fx;
		d[fx] = max(d[fx],d[fy]+1);
	}
}

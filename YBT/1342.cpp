#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#define D_MAX 0x3f3f3f3f;
using namespace std;
int n,m,s,t,k,h[101];
bool vis[101];
struct Point{
	int x,y;
}p[101];
vector<int> e[101];

double distance(Point u,Point v){
	return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

double dijstra(int s,int t){
	double d[101];
	for(int i=0;i<=n;i++)	d[i] = D_MAX;
	d[s] = 0;
	while(1){
		int k = 0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&d[k]>d[i]) k=i;
		}
		vis[k] = 1;
		if(k==t) break;
//		cout << k;
		for(int i=0;i<e[k].size();i++){
			int tt = e[k][i];
			if(!vis[tt]){
				double dt = d[k] + distance(p[k],p[tt]);
				if(dt<d[tt]) d[tt] = dt;
			}
		}
	}
	return d[t];
}

int main(){
	memset(h,-1,sizeof(h));
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> p[i].x >> p[i].y;
	cin >> m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	cin >> s >> t;
	printf("%.2lf",dijstra(s,t));
	
	return 0;
}

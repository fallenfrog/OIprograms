#include<bits/stdc++.h>
using namespace std;
int n,f[102],d[102],pre[102];
bool vis[102];
vector<int> p[102];
struct ele{
	int dist,idx;
	bool operator >(const ele& x)const{
		return dist > x.dist;
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

int find(int x){
	if(x!=f[x])	f[x] = find(f[x]);
	return f[x];
}

int prim(int root){
	d[root] = 0;
	vis[root] = 1;
	q.push({root,0});
	while(!q.empty()){
		int t = q.top().idx;
		vis[t] = 1;
		for(int i=0;i<p[t].size();i++){
			int tt = p[t][i];
			
		}
	}
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)	f[i] = i;
	for(int i=1;i<=n;i++){
		int t;
		while(cin>>t){
			if(t==0)	break;
			p[i].push_back(t);
			f[t] = i;
		}
	}
	int root = find(1);
	memset(d,0x3f,sizeof(d));
	cout << prim(root);
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,w[102][102],d[102],vis[102];
struct ele{
	int dist,idx;
	bool operator >(const ele& x)const{
		return dist > x.dist;
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

int prim(){
	d[1] = 0;
	vis[1] = 1;
	q.push({0,1});
	int ans = 0;
	while(!q.empty()){
		int t = q.top().idx;
		q.pop();
		if(!vis[t]){
			vis[t] = 1;
			ans += d[t];
		}
		for(int i=1;i<=n;i++){
			if(w[t][i]!=0 && !vis[i] && w[t][i]<d[i]){
				d[i] = w[t][i];
				q.push({d[i],i});
			}
		}
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> w[i][j];
	memset(d,0x3f,sizeof(d));
	cout << prim();
	
	return 0;
}

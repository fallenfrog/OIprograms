#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
int n,m,tree[500002],t,o,x,y;

void add(int idx,int k){
	int x = idx;
	while(x<=n){
		tree[x] += k;
		x += lowbit(x);
	}
}

int getsum(int idx){
	int ans = 0;
	while(idx){
		ans += tree[idx];
		idx -= lowbit(idx);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> t;
		add(i,t);
	}
	for(int i=1;i<=m;i++){
		cin >> o >> x >> y;
		if(o==1){
			add(x,y);
		}else{
			cout << getsum(y)-getsum(x-1) << '\n';
		}
	}

	return 0;
}


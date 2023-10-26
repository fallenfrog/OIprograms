#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
int n,m,tree[500002],a[500002],o,x,y,z;

void add(int idx,int k){
	while(idx<=n){
		tree[idx] += k;
		idx += lowbit(idx);
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
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=m;i++){
		cin >> o >> x;
		if(o==1){
			cin >> y >> z;
			add(x,z);	add(y+1,-z);
		}else{
			cout << getsum(x)+a[x] << '\n';
		}
	} 

	return 0;
}


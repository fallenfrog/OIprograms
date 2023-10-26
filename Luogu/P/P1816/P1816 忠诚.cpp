#include<bits/stdc++.h>
using namespace std;
int m,n,a[100002],d[400002],b[400002],x,y;

void build(int l,int r,int idx){
	if(l>=r){
		d[idx] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,idx<<1);	build(mid+1,r,idx<<1|1);
	d[idx] = min(d[idx<<1],d[idx<<1|1]);
}

int getmax(int l,int r,int x,int y,int idx){
	if(l==x && r==y){
		return d[idx];
	}
	int mid = (l+r)>>1;
	if(x>mid)	return getmax(mid+1,r,x,y,idx<<1|1);
	if(y<=mid)	return getmax(l,mid,x,y,idx<<1);
	return min(getmax(l,mid,x,mid,idx<<1),getmax(mid+1,r,mid+1,y,idx<<1|1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)	cin >> a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++){
		cin >> x >> y;
		cout << getmax(1,n,x,y,1) << ' ';
	}

	return 0;
}

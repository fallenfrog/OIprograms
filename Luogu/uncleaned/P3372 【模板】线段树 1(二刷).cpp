#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100002],d[400002],b[400002],o,x,y,k;

void build(int l,int r,int idx){
	if(l>=r){
		d[idx] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,idx*2);	build(mid+1,r,idx*2+1);
	d[idx] = d[idx*2]+d[idx*2+1];
}

void add(int l,int r,int x,int y,int k,int idx){
	if(l==x && r==y){
		b[idx] += k;
		return ;
	}
	int mid = (l+r)>>1;
	d[idx] += (y-x+1)*k;
	if(x>mid)	add(mid+1,r,x,y,k,idx*2+1);
	if(y<=mid)	add(l,mid,x,y,k,idx*2);
	if(x<=mid && y>mid){
		add(l,mid,x,mid,k,idx*2);
		add(mid+1,r,mid+1,y,k,idx*2+1);
	}
}

int getsum(int l,int r,int x,int y,int idx){
	if(b[idx]){
		d[idx] += (r-l+1)*b[idx];
		if(l<r)	b[idx*2] += b[idx],b[idx*2+1] += b[idx];
		b[idx] = 0;
	}
	if(l==x && r==y)	return d[idx];
	int mid = (l+r)>>1;
	if(x>mid)	return getsum(mid+1,r,x,y,idx*2+1);
	if(y<=mid)	return getsum(l,mid,x,y,idx*2);
	return getsum(l,mid,x,mid,idx*2)+getsum(mid+1,r,mid+1,y,idx*2+1);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)	cin >> a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++){
		cin >> o >> x >> y;
		if(o==1){
			cin >> k;
			add(1,n,x,y,k,1);
		}else{
			cout << getsum(1,n,x,y,1) << '\n';
		}
	}

	return 0;
}


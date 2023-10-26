#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,a[100002],d[400002],o,x,y,k,ba[400002],bm[400002];

void build(int l,int r,int idx){
	bm[idx] = 1;
	if(l>=r){
		d[idx] = a[l]%p;
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,idx<<1);	build(mid+1,r,idx<<1|1);
	d[idx] = d[idx<<1]+d[idx<<1|1];
	if(d[idx]>=p)	d[idx] -= p;
}

void add(int l,int r,int x,int y,int k,int idx){
	if(bm[idx]!=1){
		d[idx<<1] *= bm[idx],d[idx<<1|1] *= bm[idx];
		d[idx<<1] %= p,d[idx<<1|1] %= p;
		bm[idx<<1] *= bm[idx],bm[idx<<1|1] *= bm[idx];
		bm[idx] = 1;
	}
	if(l==x && r==y){
		d[idx] += (y-x+1)*k;
		d[idx] %= p;
//		if(l>=r)	return ;
		ba[idx] += k;
		return ;
	}
	int mid = (l+r)>>1;
	if(x>mid)	add(mid+1,r,x,y,k,idx<<1|1);
	else if(y<=mid)	add(l,mid,x,y,k,idx<<1);
	else{
		add(l,mid,x,mid,k,idx<<1);
		add(mid+1,r,mid+1,y,k,idx<<1|1);
	}
	d[idx] = (d[idx<<1]+d[idx<<1|1])%p;
}

void mul(int l,int r,int x,int y,int k,int idx){
	int mid = (l+r)>>1;
	if(ba[idx]){
		d[idx<<1] += ba[idx]*(mid-l+1),d[idx<<1|1] += ba[idx]*(r-mid);
		d[idx<<1] %= p,d[idx<<1|1] %= p;
		ba[idx<<1] += ba[idx],ba[idx<<1|1] += ba[idx];
		ba[idx] = 0;
	}
	if(l==x && r==y){
		d[idx] = k*d[idx]%p;
//		if(l>=r)	return ;
		bm[idx] *= k;
		return ;
	}
	if(x>mid)	mul(mid+1,r,x,y,k,idx<<1|1);
	else if(y<=mid)	mul(l,mid,x,y,k,idx<<1);
	else{
		mul(l,mid,x,mid,k,idx<<1);
		mul(mid+1,r,mid+1,y,k,idx<<1|1);
	}
	d[idx] = (d[idx<<1]+d[idx<<1|1])%p;
}

int getsum(int l,int r,int x,int y,int idx){
//	cout << l << ' ' << r << " " << x << ' ' << y << ' ' << d[idx] << ' ' << idx << '|';
//	if(l==x && r==y)	cout << idx << ' ' << d[idx] << '\n';
	if(l==x && r==y)	return d[idx];
	int mid = (l+r)>>1;
	if(bm[idx]!=1){
		d[idx<<1] *= bm[idx],d[idx<<1|1] *= bm[idx];
		d[idx<<1] %= p,d[idx<<1|1] %= p;
		bm[idx<<1] *= bm[idx],bm[idx<<1|1] *= bm[idx];
		bm[idx] = 1;
	}
	if(ba[idx]){
//		cout << l << ' ' << r << ' ' << ba[idx] << ' ' << idx << '\n';
		d[idx<<1] += ba[idx]*(mid-l+1),d[idx<<1|1] += ba[idx]*(r-mid);
		d[idx<<1] %= p,d[idx<<1|1] %= p;
		ba[idx<<1] += ba[idx],ba[idx<<1|1] += ba[idx];
		ba[idx] = 0;
	}
	if(x>mid)	return getsum(mid+1,r,x,y,idx<<1|1);
	else if(y<=mid)	return getsum(l,mid,x,y,idx<<1);
	else	return (getsum(l,mid,x,mid,idx<<1)+getsum(mid+1,r,mid+1,y,idx<<1|1))%p;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m >> p;
	for(int i=1;i<=n;i++)	cin >> a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++){
		cin >> o >> x >> y;
		if(o==2){
			cin >> k;
			add(1,n,x,y,k,1);
//			cout << "d: " << d[8] << ' ' << d[9] << ' ' << d[5] << ' ' << d[6] << ' ' << d[7] << ' ' << d[3] << '\n';
//			cout << "ba:" << ba[1] << ' ' << ba[4] << ' ' << ba[2] << ' ' << ba[3] << '\n';
		}
		else if(o==1){
			cin >> k;
			mul(1,n,x,y,k,1);
//			cout << "d: " << d[8] << ' ' << d[9] << ' ' << d[5] << ' ' << d[6] << ' ' << d[7] << '\n';
//			cout << "bm:" << bm[4] << ' ' << bm[2] << ' ' << bm[3] << '\n';
		}
		else{
			cout << getsum(1,n,x,y,1) << '\n';
//			cout << "d: " << d[8] << ' ' << d[9] << ' ' << d[5] << ' ' << d[6] << ' ' << d[7] << ' ' << d[3] << ' ' << d[2] << ' ' << d[1] << '\n';
//			cout << "ba:" << ba[1] << ' ' << ba[4] << ' ' << ba[2] << ' ' << ba[3] << '\n';
		}
	}

	return 0;
}

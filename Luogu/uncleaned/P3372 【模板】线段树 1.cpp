#include<bits/stdc++.h>
#define int long long
#define N 100002
using namespace std;
int n,m;
int a[N],d[4*N],b[4*N];

void build(int l,int r,int idx){
	if(l==r){
		d[idx] = a[l];
		return ;
	}
	int m = (l+r)>>1;
	build(l,m,idx*2);
	build(m+1,r,idx*2+1);
	d[idx] = d[idx*2] + d[idx*2+1];
}

void update(int f,int e,int l,int r,int idx,int k){
	if(f==l && e==r){
		b[idx] += k;
		return ;
	}
	d[idx] += (e-f+1)*k;
	int m = (l+r)>>1;
	if(f>m){
		update(f,e,m+1,r,idx*2+1,k);
		return ;
	}
	if(e<=m){
		update(f,e,l,m,idx*2,k);
		return ;
	}
	if(m>=f && m<e){
		update(f,m,l,m,idx*2,k);
		update(m+1,e,m+1,r,idx*2+1,k);
		return ;
	}
}

int getsum(int f,int e,int l,int r,int idx){
	if(b[idx]){
		d[idx] += b[idx]*(r-l+1);
		if(l!=r){
			b[idx*2] += b[idx];
			b[idx*2+1] += b[idx];
		}
		b[idx] = 0;
	}
	if(f==l && e==r)	return d[idx];
	int m = (l+r)>>1;
	if(f>m)	return getsum(f,e,m+1,r,idx*2+1);
	if(e<=m)return getsum(f,e,l,m,idx*2);
	if(m>=f && m<e)	return getsum(f,m,l,m,idx*2)+getsum(m+1,e,m+1,r,idx*2+1);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	build(1,n,1);
	int op,l,r,k;
	for(int i=1;i<=m;i++){
		cin >> op >> l >> r;
		if(op==1){
			cin >> k;
			update(l,r,1,n,1,k);
		}else{
			cout << getsum(l,r,1,n,1) << '\n';
		}
	}
	
	return 0;
}

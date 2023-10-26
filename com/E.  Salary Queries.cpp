#include<bits/stdc++.h>
using namespace std;
int n,q,a[200002],maxn[800002],minn[800002];

int read(){
	int t = 0;	char ch;
	while(!isdigit(ch=getchar()));	t += ch-'0';
	while(isdigit(ch=getchar()))	t = t*10+ch-'0';
	return t;
}

void build(int l,int r,int idx){
	if(l==r){
		maxn[idx] = minn[idx] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,idx<<1);	build(mid+1,r,(idx<<1)+1);
	maxn[idx] = max(maxn[idx<<1],maxn[(idx<<1)+1]);
	minn[idx] = min(minn[idx<<1],minn[(idx<<1)+1]);
}

void update(int l,int r,int x,int k,int idx){
	if(l==r){
		maxn[idx] = minn[idx] = a[x] = k;
		return ;
	}
	int mid = (l+r)>>1;
	if(x>mid)	update(mid+1,r,x,k,(idx<<1)+1);
	else		update(l,mid,x,k,idx<<1);
	maxn[idx] = max(maxn[idx<<1],maxn[(idx<<1)+1]);
	minn[idx] = min(minn[idx<<1],minn[(idx<<1)+1]);
}

int get(int l,int r,int x,int y,int idx){
	if(l==r && (a[l]>y || a[l]<x))	return 0;
	if(minn[idx]>y || maxn[idx]<x)	return 0;
	if(minn[idx]>=x && maxn[idx]<=y)	return r-l+1;
	int mid = (l+r)>>1;
	return get(l,mid,x,y,idx<<1)+get(mid+1,r,x,y,(idx<<1)+1);
}

int main(){
	n = read(),	q = read();
	for(int i=1;i<=n;i++)	a[i] = read();
	build(1,n,1);
	char c;	int l,r;
	while(q--){
		c = getchar();
		l = read(),r = read();
		if(c=='!')	update(1,n,l,r,1);
		if(c=='?')	cout << get(1,n,l,r,1) << ' ';
	}
	
	return 0;
}

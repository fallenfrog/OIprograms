#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,ans1,ans2;
int f[10000002],a[10000002];
struct ele{
	int l,r,k;
	bool operator >(const ele& other)const{
		return k > other.k;
	}
}e[200002];

int find(int x){
	if(x!=f[x])	f[x] = find(f[x]);
	return f[x];
}

void merge(int a,int b){
	int fa = find(a),fb = find(b);
	if(fa!=fb){
		if(fb<fa)	swap(fb,fa);
		f[fa] = fb;
	}
}

signed main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	int q = 0;
	for(int i=1;i<=n;i++){
		int t,w;
		scanf("%lld%lld",&t,&w);
		q += t;	ans1 += w;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].l,&e[i].r,&e[i].k);
		e[i].r--;	e[i].r = min(e[i].r,p);
	}
	for(int i=1;i<=p+1;i++)	f[i] = i;
	sort(e+1,e+m+1,greater<ele>());
	for(int i=1;i<=m;i++){
		int l = e[i].l,r = e[i].r,k = e[i].k;
		l = find(l);
		while(l<=r){
			a[l] = k;
			merge(l,l+1);
			l = find(l);
		}
	}
	nth_element(a+1,a+q+1,a+p+1);
	for(int i=q+1;i<=p;i++){
		ans2 += a[i];
	}
	printf("%lld %lld",ans1,ans2);
	
	return 0;
}

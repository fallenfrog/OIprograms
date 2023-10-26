#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,v,a[1000002],l[1000002],h[1000002],cnt,sum,t;
struct edge{
	int v,w,nxt;
}e[2000002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;	memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum += a[i]; t = a[i];
		while(t){t /= 10,l[i]++;}
		if(a[i]==0)	l[i] = 1;
		if(sum>=mod)	sum -= mod;
	}
	for(int i=2;i<=n;i++){
		cin >> v;
		e[cnt].v = v;
		e[cnt].nxt = h[i];
		h[i] = cnt++;
		e[cnt].v = i;
		e[cnt].nxt = h[v];
		h[v] = cnt++;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			sum += Get
		}
	}
	
	
	return 0;
}

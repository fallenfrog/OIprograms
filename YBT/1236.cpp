#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,r = 0,l = INF;
bool d[40005],lazy[40005],a[10005];
struct Node{
	int a,b;
}e[50005];

void update(int b,int e,int l,int r,int idx){
	if(l>=b && r<=e){
		d[idx] = 1;
		lazy[idx*2] = lazy[idx*2+1] = 1;
		return ;
	}
	int m = (l+r)>>1;
	if(m<b){
		update(b,e,m+1,r,idx*2+1);
	}
	if(m>=e){
		update(b,e,l,m,idx*2);
	}
	if(m>=b && m<e){
		update(b,m,l,m,idx*2);
		update(m+1,e,m+1,r,idx*2+1);
	}
}

bool get(int l,int r,int idx){
	if(lazy[idx]){
		lazy[idx] = 0;
		d[idx] = 1;
		if(l!=r){
			lazy[idx*2] = lazy[idx*2+1] = 1;
		}
	}
	if(l==r)	return d[idx];
	else{
		int m = (l+r)>>1;
		return get(l,m,idx*2)&&get(m+1,r,idx*2+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> e[i].a >> e[i].b;
		e[i].b--;
		l = min(l,e[i].a);
		r = max(r,e[i].b);
	}
	for(int i=1;i<=n;i++){
		if(e[i].a>e[i].b)	continue;
		update(e[i].a,e[i].b,l,r,1);
	}
	if(get(l,r,1)){
		cout << l << ' ' << r+1;
	}else{
		cout << "no";
	}
	
	return 0;
} 

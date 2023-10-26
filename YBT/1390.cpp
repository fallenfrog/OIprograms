#include<bits/stdc++.h>
using namespace std;
const int maxn = 50001;
int n,k,cnt,p[3*maxn],d[3*maxn];

void init(int n);
int find(int x);
void memge(int x,int y);
bool same(int x,int y);

int main(){
	cin >> n >> k;
	init(n);
	for(int i=0;i<k;i++){
		int q,x,y;
		cin >> q >> x >> y;
		if((x>n || y>n) || (q==2 && x==y))
			cnt++;
		else if(q==1){
			if(same(x+maxn,y) || same(x,maxn+y))
				cnt++;
			else{
				memge(x,y);
				memge(x+maxn,y+maxn);
				memge(x+2*maxn,y+2*maxn);
			}
		}
		else if(q==2){
			if(same(x,y) || same(x,y+maxn))
				cnt++;
			else{
				memge(x+maxn,y);
				memge(x+2*maxn,y+maxn);
				memge(x,y+2*maxn);
			}
		}
	}
	cout << cnt;
	
	return 0;
}

void init(int n){
	for(int i=1;i<=n;i++){
		p[i] = i;
		p[i+maxn] = i+maxn;
		p[i+2*maxn] = i+2*maxn;
	}
}

int find(int x){
	if(x!=p[x])	p[x] = find(p[x]);
	return p[x];
}

void memge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx!=fy){
		if(d[fx]<d[fy])	swap(fx,fy);
		p[fy] = fx;
		d[fx] = max(d[fx],d[fy]+1);
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

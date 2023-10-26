#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct point{
	int x,y;
}p[1002];

bool cmp1(point a,point b){return a.x<b.x;}
bool cmp2(point a,point b){return a.y<b.y;}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> p[i].x >> p[i].y;
	sort(p+1,p+1+n,cmp1);
	int dx = p[n].x-p[1].x;
	sort(p+1,p+1+n,cmp2);
	int dy = p[n].y-p[1].y;
	int t = max(dx,dy);
	cout << t*t;
	
	return 0;
}

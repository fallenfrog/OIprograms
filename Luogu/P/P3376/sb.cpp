#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n, m, s, t, ans;
struct point{
	int pos, nex, len;
}f[10009];
int h[209], dep[209], cur[209], idx;
void add(int x, int y, int len){
	f[idx ++].nex = h[x];
	f[idx].len = len;
	f[idx].pos = y;
	h[x] = idx;
}
bool bfs(){
	memset(dep, -1, sizeof(dep));
	memcpy(cur, h, sizeof(h));
	queue<int>p;
	p.push(s);
	dep[s] = 1;
	while(!p.empty()){
		int k = p.front(); p.pop();
		for(int i = h[k]; ~i; i = f[i].nex ){
			int j = f[i].pos;
			if(dep[j] == -1 && f[i].len) {
				dep[j] = dep[k] + 1;
				p.push(j);
			}
		}		
	}
	return dep[t] != -1;
}
int dfs(int pos = s, int num = 1145141919){
	if(pos == t) 
		return num;
	int first = num;
	for(int i = cur[pos]; num && ~i; i = f[i].nex){
		cur[pos] = i;
		int j = f[i].pos;
		if(f[i].len && dep[j] == dep[pos] + 1){
			int low = dfs(j, min(f[i].len, num));
			num -= low;
			f[i].len -= low;
			f[i ^ 1].len += low;
		}
	}
	return first - num;
}
signed main(){
	memset(h, -1, sizeof(h));
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m ; i ++ ){
		int x, y, len;
		cin >> x >> y >> len;
		add(x, y, len);
		add(y, x, 0);
	}
	while(bfs()){
		ans += dfs();
	}
	cout << ans << '\n';
	return 0;
}
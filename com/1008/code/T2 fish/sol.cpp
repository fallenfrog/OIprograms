#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

int n, m, h[N], k, tu, tv, f[N];
bool vis[N], blk[N << 1], used[N << 1];
struct edge{
	int v, nxt;
}e[N << 1];
set<int> st; //表示奇数度点集
vector<int> v[N]; // 存每个连通块所有方案对应黑边数

void dfs(int s, int x, int res){
	// cerr << x << " begin\n";
	vis[x] = 1, f[x] = s;
	for(int i = h[x]; ~i; i = e[i].nxt){
		if(blk[i] || blk[i ^ 1] || used[i])  continue;
		used[i ^ 1] = used[i] = 1;
		int V = e[i].v;
		blk[i] = blk[i ^ 1] = 1;
		if(!st.count(x))  st.insert(x);
		else  st.erase(x);
		if(!st.count(V))  st.insert(V);
		else  st.erase(V);
		if(st.empty())
			v[s].push_back(res + 1)/*, cerr << "push " << res + 1 << '\n'*/;
		// cerr << x << " search " << V << '\n';
		dfs(s, V, res + 1);
		blk[i] = blk[i ^ 1] = 0;
		if(!st.count(x))  st.insert(x);
		else  st.erase(x);
		if(!st.count(V))  st.insert(V);
		else  st.erase(V);
		dfs(s, V, res);
		used[i] = used[i ^ 1] = 0;
	}
}

int cnt[N], ans, tot;
pair<int, int> eg[N];
void solve1(){
	bool shit;
	for(int i = 1; i <= m; i ++)  cin >> eg[i].first >> eg[i].second;
	for(int s = 1; s < (1 << m); s ++){
		shit = 0, tot = 0;
		for(int i = 1; i <= m; i ++)
			if((s >> i - 1) & 1)
				tot ++,
				cnt[eg[i].first] ++,
				cnt[eg[i].second] ++;
		for(int i = 1; i <= n; i ++){
			if(cnt[i] & 1)
				shit = 1;
			cnt[i] = 0;
		}
		if(!shit)  ans += tot * tot;
	}
	cout << ans << '\n';
}

int main(){
	FileIO("fish");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	if(n <= 15){
		solve1();
		return 0;
	}
	for(int i = 1; i <= n; i ++)	f[i] = i, h[i] = -1;
	for(int i = 1; i <= m; i ++){
		cin >> tu >> tv;
		e[k] = {tv, h[tu]}, h[tu] = k ++;
		e[k] = {tu, h[tv]}, h[tv] = k ++;
	}
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			st.clear();
			dfs(i, i, 0);
		}
	}
	for(int i = 1; i <= n; i ++){
		if(i == f[i]){
			cerr << i << '\n';
			for(auto t : v[i]){
				cerr << t << ' ';
			}
			cerr << '\n';
		}
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "rank";
const int N = 500 + 2;
const int K = 5 + 2;

int n, k, a[N][K], ans[N][N], ov[N][N], t[N], rnk[N], last[N], cnt[K], tmp[N];
struct node{
	int x, y, d, over;
	
	bool operator > (const node& other) const{
		return d > other.d;
	}
};
priority_queue <node, vector<node>, greater<node> > q;

void work(){
	// 把所有 a 超越 b 的日期加入堆 
	// ,,,不会 k=1 
	int len = 1, t = 0;
	bool over = 0;
	for(int i = 2; i <= k; i ++)
		len = len * i / __gcd(len, i);
	for(int i = 1; i <= k; i ++)
		cnt[i] = len / i;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			tmp[i] += a[i][j] * cnt[j];
		}
	}
	for(int i = 1; i < n; i ++){
		for(int j = i + 1; j <= n; j ++){
			int x = i, y = j;
			if(a[x][0] > a[y][0])  swap(x, y);
			if(tmp[x] < tmp[y])  continue;
			t = (a[x][0] - a[y][0]) / (tmp[y] - tmp[x]) * len;
			if(t * (tmp[y] - tmp[x]) == (a[x][0] - a[y][0]) * len){
				q.push(node{x, y, t, 1});
				q.push(node{x, y, t + 1, -1});
			}else{
				q.push(node{x, y, t + 1, 0});
			}
		}
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		t[i] = i;
		for(int j = 0; j <= k; j ++){
			cin >> a[i][j];
		}
	}
//	for(int i = 1; i <= n; i ++)  cerr << t[i] << ' ';  cerr << '\n';
	sort(t + 1, t + n + 1, [](int x, int y){return a[x][0] > a[y][0];});
//	for(int i = 1; i <= n; i ++)  cerr << t[i] << ' ';  cerr << '\n';
	for(int i = 1; i <= n; i ++){
		if(t[i] == t[i - 1])  rnk[t[i]] = rnk[t[i - 1]];
		else  rnk[t[i]] = i;
//		cerr << t[i] << ' ' << i << '\n';
	}
	work();
	while(!q.empty()){
		node t = q.top();  q.pop();
		cerr << t.x << ' ' << t.y << ' ' << t.d << ' ' << t.over << '\n';
		ans[t.x][rnk[t.x]] += t.d - last[t.x],
		ans[t.y][rnk[t.y]] += t.d - last[t.y];
		if(!t.over)
			rnk[t.x] ++, rnk[t.y] --;
		else if(t.over == 1)
			rnk[t.x] = rnk[t.y];
		else
			rnk[t.y] --;
		last[t.x] = last[t.y] = t.d;
	}
	for(int i = 1; i <= n; i ++)
		ans[i][rnk[i]] = -1;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}


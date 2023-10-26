#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

inline int read(){
	int res = 0, f = 1; char c;
	while(!isdigit(c = getchar()))  if(c == '-')  f = -1;  res = c - '0';
	while(isdigit(c = getchar()))  res = (res << 3) + (res << 1) + c - '0';
	return res * f;
}

inline void write(int x){
	if(x / 10)  write(x / 10);
	putchar(x % 10 + '0');
}

int n, a[N], q, pos[N], ans[N];
struct node{
	int l, r, idx;
	bool operator < (const node& other) const {
		return r == other.r ? l < other.l : r < other.r;
	}
}qs[N];

inline int lowbit(int x){return x &- x;}
int d[N];
void add(int x, int k){	for(; x <= n; d[x] += k, x += lowbit(x));}
int query(int x){int res = 0; for(; x; res += d[x], x -= lowbit(x)); return res;}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	n = read();
	for(int i = 1; i <= n; i ++)  a[i] = read();
	q = read();
	for(int i = 1; i <= q; i ++)  qs[i] = {read(), read(), i};
	sort(qs + 1, qs + q + 1);
	int r = 0;
	for(int i = 1; i <= q; i ++){
		while(r < qs[i].r){
			r ++;
			if(pos[a[r]])  add(pos[a[r]], -1);
			pos[a[r]] = r;
			add(r, 1);
		}
		ans[qs[i].idx] = query(qs[i].r) - query(qs[i].l - 1);
	}
	for(int i = 1; i <= q; i ++)  cout << ans[i] << '\n';
	
	return 0;
}

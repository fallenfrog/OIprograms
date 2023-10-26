#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;
const int Q = 1e6 + 2;
const int A = 1e6 + 2;

int n, a[N], q, len, bel[N], ans[Q], ql, qr, cnt[A];
struct node{
	int l, r, idx;
	bool operator < (const node& other) const{
		return (bel[l] ^ bel[other.l]) ? (bel[l] < bel[other.l]) : ((bel[l] & 1) ? r < other.r : r > other.r);
	}
}qs[Q];

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

int main(){
	//FileIO();
	n = read(), len = sqrt(n);
	for(int i = 1; i <= n; i ++){
		bel[i] = (i - 1) / len + 1;
		a[i] = read();
	}
	q = read();
	for(int i = 1; i <= q; i ++){
		ql = read(), qr = read();
		qs[i] = {ql, qr, i};
	}
	sort(qs + 1, qs + q + 1);
	int l = 1, r = 0, now = 0;
	for(int i = 1; i <= q; i ++){
		ql = qs[i].l, qr = qs[i].r;
		while(l < ql)  now -= ! -- cnt[a[l ++]];
		while(l > ql)  now += ! cnt[a[-- l]] ++;
		while(r < qr)  now += ! cnt[a[++ r]] ++;
		while(r > qr)  now -= ! -- cnt[a[r --]];
		ans[qs[i].idx] = now;
	}
	for(int i = 1; i <= q; i ++)  write(ans[i]), putchar('\n');

	return 0;
}

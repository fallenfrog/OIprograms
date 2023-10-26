#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e5 + 2;
const int Q = 3e5 + 2;

int n, T, l1, r1, l2, r2;
string s;
int cnt[130];

void solve1(){
	cin >> l1 >> r1 >> l2 >> r2;
	string s1 = s.substr(l1 - 1, r1 - l1 + 1);
	string s2 = s.substr(l2 - 1, r2 - l2 + 1);
	for(auto t : s1)  cnt[t] ++;
	for(auto t : s2)  cnt[t] --;
	for(int i : cnt)  if(cnt[i]){  cout << "0\n";  return ;}
	string t1, t2;
	
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> T >> s;
	while(T --)  solve1;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1725";
const int N = 2e5 + 2;

namespace genshin{
	template <typename T>
	struct queue{
		T a[N];
		int l = 1, r = 0;
		void push_back(T x){a[++ r] = x;}
		void pop_back(){r --;}
		void pop_front(){l ++;}
		T front(){return a[l];}
		T back(){return a[r];}
		int size(){return r - l + 1;}
		bool empty(){return r < l;}
	};
	
	template <typename T>
	struct stack{
		T a[N];
		int t = 0;
		void push(T x){a[++ t] = x;}
		void pop(){t --;}
		T top(){return a[t];}
		int size(){return t;}
		bool empty(){return t;}
	};
};

int n, l, r, v[N << 1], dp[N << 1];
struct node{int val, idx;};
genshin::queue <node> mx;

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> l >> r;
	for(int i = 0; i <= n; i ++){
		cin >> v[i];
		if(i)  dp[i] = -2e9;
		if(i >= l){
			while(!mx.empty() && dp[i - l] > mx.back().val)  mx.pop_back();
			mx.push_back(node{dp[i - l], i - l});
			dp[i] = mx.front().val + v[i];
			if(!mx.empty() && mx.front().idx + r <= i)  mx.pop_front();
		}
	}
	int ans = -2e9;
	for(int i = n - r + 1; i <= n; i ++)  ans = max(ans, dp[i]);
	cout << ans;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;

namespace genshin{
	template <typename T>
	struct queue{
		T a[N];
		int l = 1, r = 0;
		void push_back(T x){a[++ r] = x;}
		void pop_back(){r --;}
		void pop_front(){l ++;}
		T front(){return a[l];}
		int size(){return r - l + 1;}
		bool empty(){return r >= l;}
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
	
	template <typename T>
	struct BIT{
		T d[N];
		int n = 0;
		inline int lowbit(int x){return x &- x;}
		BIT(int x){n = x;}
		void add(int x, T k){
			while(x <= n){
				d[x] += k;
				x += lowbit(x);
			}
		}
		T query(int x){
			T res = 0;
			while(x){
				res += d[x];
				x -= lowbit(x);
			}
			return res;
		}
	};
};

int n, d;
genshin::queue<int> mx, mn;

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	return 0;
}

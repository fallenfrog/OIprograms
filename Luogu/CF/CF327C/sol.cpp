#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int mod = 1e9 + 7;

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
	
	struct Matrix{
		int n = 2, a[5][5];
		Matrix(int p = 0){
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= n; j ++)
					a[i][j] = 0;
			if(p)
				for(int i = 1; i <= n; i ++)
					a[i][i] = 1;
		}
		Matrix operator * (const Matrix& other){
			Matrix res;
			for(int i = 1; i <= n; i ++){
				for(int j = 1; j <= n; j ++){
					for(int k = 1; k <= n; k ++){
						res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % mod;
					}
				}
			}
			return res;
		}
		Matrix operator % (const int& mod){  return *this;}
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

int k, d[N], len, temp, p;
string s;
genshin::Matrix ans, t;

template <typename T>
T qpow(T b, int p){
	T res(1);
	for(; p; p >>= 1, b = b * b % mod)  if(p & 1)  res = res * b % mod;
	return res;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s >> k;  len = s.size();
	for(int i = 0; i < len; i ++){
		if(s[i] == '0' || s[i] == '5'){
			p = (p + qpow(2ll, i)) % mod;
		}
	}
	temp = qpow(2ll, len);
	ans.a[1][1] = t.a[1][1] = 1, t.a[1][2] = p, t.a[2][2] = temp;
	ans = ans * qpow(t, k);
	cout << ans.a[1][2];

	return 0;
}

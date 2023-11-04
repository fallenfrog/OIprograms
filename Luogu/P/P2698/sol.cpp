#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "2698";
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

genshin::queue <int> mx, mn;
int n, d, l = 1, r = 0, ans = 0x3f3f3f3f;
struct node{
	int x, y;
}nd[N];

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> d;
	for(int i = 1; i <= n; i ++)  cin >> nd[i].x >> nd[i].y;
	sort(nd + 1, nd + n + 1, [](node a, node b){return a.x < b.x;});
	while(r <= n){
		while(r <= n && (mx.empty() || mn.empty() || nd[mx.front()].y - nd[mn.front()].y < d)){
			r ++;
			cerr << l << ' ' << r << '\n';
			while(!mx.empty() && nd[mx.back()].y < nd[r].y)  mx.pop_back();  mx.push_back(r);
			while(!mn.empty() && nd[mn.back()].y > nd[r].y)  mn.pop_back();  mn.push_back(r);
		}
		while(l <= r && (!mx.empty() && !mn.empty() && nd[mx.front()].y - nd[mn.front()].y >= d)){
			ans = min(ans, nd[r].x - nd[l].x);
			l ++;
			cerr << l << ' ' << r << '\n';
			while(!mx.empty() && nd[mx.front()].x < nd[l].x)  mx.pop_front();
			while(!mn.empty() && nd[mn.front()].x < nd[l].x)  mn.pop_front();
		}
		cerr << "r=" << r << '\n';
	}
	cout << (ans == 0x3f3f3f3f ? -1 : ans);

	return 0;
}

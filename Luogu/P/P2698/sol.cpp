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
int n, d, l, ans = 0x3f3f3f3f;
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
	for(int i = 1; i <= n; i ++){
		while(!mx.empty() && nd[mx.back()].y < nd[i].y)  mx.pop_back();  mx.push_back(i);
		while(!mn.empty() && nd[mn.back()].y > nd[i].y)  mn.pop_back();  mn.push_back(i);
		cerr << "max:" << mx.front() << " min:" << mn.front() << '\n';
		while(l < i && !mx.empty() && !mn.empty() && (!l || nd[mx.front()].y - nd[mn.front()].y < d)){
			l ++;
			cerr << l << ' ' << mx.front() << ' ' << mn.front() << ' ' << i << '\n';
			if(!mx.empty() && mx.front() < l)  mx.pop_front();
			if(!mn.empty() && mn.front() < l)  mn.pop_front();
		}
		cerr << l << ' ' << i << '\n';
		ans = min(ans, nd[i].x - nd[l].x);
	}
	cout << (ans == 0x3f3f3f3f ? -1 : ans);

	return 0;
}

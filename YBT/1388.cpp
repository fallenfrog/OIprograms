#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> idx;
string gen[50010];
int n;
int p[50010];

int find(int x);
void memge(int x,int y);

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	string s;
	int u,v;
	while(cin>>s){
		char c = s[0];
		s.erase(s.begin());
		if(idx[s]==0){
			idx[s] = ++n;
			gen[idx[s]] = s;
			p[idx[s]] = idx[s];
		}
		switch(c){
			case '$':
				return 0;
			case '#':
				u = idx[s];
				break;
			case '+':
				v = idx[s];
				memge(u,v);
				break;
			case '?':
				cout << s << ' ' << gen[find(idx[s])] << '\n';
				break;
		}
	}
	
	return 0;
}

int find(int x){
	if(p[x]!=x)	p[x] = find(p[x]);
	return p[x];
}

void memge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx!=fy){
		p[fy] = fx;
	}
}

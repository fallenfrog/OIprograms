#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "lis";
const int N = 1e5 + 2;

int n, sum, mx, tmp;
bool flag;
string s; 

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s;  s.push_back('#');
	for(int i = 0; i <= n; i ++){
		if(flag){
			if(s[i] == '<')  tmp ++;
			else{
				sum += tmp;
				mx = max(mx, tmp);
				flag = 0;
			}
		}
		else if(s[i] == '<'){
			flag = 1;
			tmp = 1;
		}
	}
	cout << mx + 1 << ' ' << sum + 1;

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "chemistry";
const int N = 2e6 + 2;

int tmp, c, h, o, n, oh, nh2, ch3, cn;
char last;
string s; 

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> s;  s += '#';
	for(auto ch : s){
		if(ch >= '0' && ch <= '9'){
			tmp = tmp * 10 + ch - '0';
		}else{
			if(!tmp)  tmp = 1;
			if(last == 'C')  c += tmp;
			else if(last == 'H')  h += tmp;
			else if(last == 'O')  o += tmp;
			else if(last == 'N')  n += tmp;
			tmp = 0, last = ch;
		}
	}

	return 0;
}


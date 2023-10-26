#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
stack<int> ns;
stack<char> ops;
string s;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	getline(cin,s);
	int len = s.size(),t = 0,i = 0;
	while(s[i]!='@'){
		char c = s[i++];
		if(c==' '){
			ns.push(t);
			t = 0;
		}else{
			if(c>='0' && c<='9'){
				t = c-'0'+t*10;
			}else{
				int b = ns.top();	ns.pop();
				int a = ns.top();	ns.pop();
				if(c=='+')	ns.push(a+b);
				else if(c=='-')	ns.push(a-b);
				else if(c=='*')	ns.push(a*b);
				else if(c=='/')	ns.push(a/b);
			}
		}
	}
	cout << ns.top();
	
	return 0;
} 

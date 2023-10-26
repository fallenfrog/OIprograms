#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string t;

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		stack<char> c;
		for(int j=0;j<t.size();j++){
			if(!c.empty() && t[j]==c.top()){
				c.pop();
			}else{
				c.push(t[j]);
			}
		}
		if(c.empty())	cnt++;
	}
	cout << cnt;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string str;
map<char,int> m;
stack<int> cs;

int main(){
	m['('] = 1;	m[')'] = -1;
	m['['] = 2;	m[']'] = -2;
	getline(cin,str);
	int l = str.size();
	for(int i=0;i<l;i++){
		if(!cs.empty() && cs.top()+m[str[i]]==0){
			cs.pop();	continue;
		}
		cs.push(m[str[i]]);
	}
	if(!cs.empty())		cout << "Wrong";
	else				cout << "OK";
	
	return 0;
}

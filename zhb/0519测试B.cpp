#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a=-1,b=-1,c=-1,idx;
bool flag;//1+0-

void f(int& t){
	t = 0;
	while(idx<s.size() && isdigit(s[idx])){
		t = t*10+s[idx]-'0',idx++;
	}
}

int calc(int a,int b,int c,bool flag){
	if(c==-1){
		if(flag)	return a+b;
		else		return a-b;
	}
	if(a==-1){
		if(flag)	return c-b;
		else		return c+b;
	}
	if(b==-1){
		if(flag)	return c-a;
		else		return a-c;
	}
} 

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	getline(cin,s);
	if(s[0]=='?'){
		idx++;
	}else
		f(a);
	if(s[idx]=='+')	flag = 1;
	idx++;
	if(s[idx]=='?'){
		idx++;
	}else
		f(b);
	idx++;
	if(s[idx]!='?')	f(c);
	cout << calc(a,b,c,flag);
	
	return 0;
}

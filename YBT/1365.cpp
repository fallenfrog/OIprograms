#include<bits/stdc++.h>
using namespace std;
int n;
string s;

char fbi(int n,string s){
	char ans;
	if(n==0){
		if(s[0]=='0'){
			ans = 'B';
		}else{
			ans = 'I';
		}
	}else{
		char c1 = fbi(n-1,s.substr(0,s.size()/2));
		char c2 = fbi(n-1,s.substr(s.size()/2,s.size()/2));
		if(c1!=c2){
			ans = 'F';
		}else{
			ans = c1;
		}
	}
	cout << ans;
	return ans;
}

int main(){
	cin >> n >> s;
	fbi(n,s);
	
	return 0;
}

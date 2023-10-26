#include<bits/stdc++.h>
using namespace std;
int maxx=0,minn=100,let[52];

bool ss(int n){
	if(n==0||n==1) return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	string str;
	cin >> str;
	for(int i=0;i<str.length();i++){
		if(str[i]>'A'&&str[i]<'Z'){
			let[(int)str[i]-65]++;
		}
		if(str[i]>'a'&&str[i]<'z'){
			let[(int)str[i]-71]++;
		} 
	}
	for(int i=0;i<52;i++){
		if(let[i]>maxx){
			maxx=let[i];
		}
		if(let[i]<minn&&let[i]){
			minn=let[i];
		}
	} 
	if(ss(maxx-minn)) cout << "Lucky Word" << endl << maxx-minn;
	else cout << "No Answer" << endl << 0;
	
	return 0;
} 

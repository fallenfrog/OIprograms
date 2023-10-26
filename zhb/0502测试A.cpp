#include<bits/stdc++.h>
using namespace std;
map<char,char> p;
string s1,s2,s3;

int main(){
	cin >> s1 >> s2;
	int len = s1.size();
	if(len!=s2.size()){
		cout << "Failed";
		return 0;
	}
	for(int i=0;i<=len;i++){
		if((int)p[s1[i]]!=0 && p[s1[i]]!=s2[i]){
			cout << "Failed";
			return 0;
		}
		p[s1[i]] = s2[i];
	}
	for(char i='A';i<='Z';i++){
		if((int)p[i]==0){
			cout << "Failed";
			return 0;
		}
	}
	cin >> s3;
	for(int i=0;i<s3.size();i++){
		cout << p[s3[i]];
	}
	
	return 0;
}

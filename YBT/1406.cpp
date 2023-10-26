#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,st;
int i,j,l,l1,l2;

int main(){
	getline(cin,s);
	cin >> s1 >> s2;
	l = s.length(); l1 = s1.length(); l2 = s2.length();
	for(i=0;i<l;i++){
		for(j=0;j<l1;j++){
			if(s[i+j]!=s1[j]){
				break;
			}
			if(i>0&&s[i-1]!=' '){
				break;
			}
		}
		if(j==l1){
			s.erase(i,j);
			s.insert(i,s2);
		}
	}
	cout << s;
	
	return 0;
}

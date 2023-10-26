#include<bits/stdc++.h>
using namespace std;
string s1,s2;

int main(){
	getline(cin,s1);
	getline(cin,s2);
	int l1=s1.length(),l2=s2.length();
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			if(toupper(s1[i+j])==toupper(s2[j])){
				break;
			}
			if(i>0&&s1[i]!=' '){
				break;
			}
		}
		if(j==l2);
	}
	return 0;
}

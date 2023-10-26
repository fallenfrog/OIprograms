#include<bits/stdc++.h>
using namespace std;
int k,cnt=1;
string s;

int main(){
	cin >> k;
	getline(cin,s);
	getline(cin,s);
	int len = s.size();
	for(int i=1;i<len;i++){
		if(s[i]==s[i-1]){
			cnt++;
		}else{
			if(cnt>=k){
				cout << s[i-1];
				return 0;
			}
			cnt = 1;
		}
	}
	
	cout << "No";
	return 0;
}

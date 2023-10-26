#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int n;
string s1,s2,result[100];

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s1 >> s2;
		if(s1[0]=='R'){
			if(s2[0]=='R'){
				result[i] = "Tie";
			}
			if(s2[0]=='S'){
				result[i] = "Player1";
			}
			if(s2[0]=='P'){
				result[i] = "Player2";
			}
		}
		if(s1[0]=='S'){
			if(s2[0]=='R'){
				result[i] = "Player2";
			}
			if(s2[0]=='S'){
				result[i] = "Tie";
			}
			if(s2[0]=='P'){
				result[i] = "Player1";
			}
		}
		if(s1[0]=='P'){
			if(s2[0]=='R'){
				result[i] = "Player1";
			}
			if(s2[0]=='S'){
				result[i] = "Player2";
			}
			if(s2[0]=='P'){
				result[i] = "Tie";
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << result[i] << endl;
	}
	return 0;
} 

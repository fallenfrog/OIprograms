#include<iostream>
#include<string>
using namespace std;
int t,m,n,a[20][20];
string str;

int main(){
	cin >> str;
	for(int i=0;i<str.length()/2;i++){
		if(str[i]!=str[str.length()-i-2]){
			cout << "No";
			t = 1;
			break;
		}
	}
	if(!t) cout << "Yes"; 
	
	return 0;
}

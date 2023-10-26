#include<bits/stdc++.h>
using namespace std;
string str,t;
int n;

int main(){
	getline(cin,str);	int len = str.size();
	for(int i=0;i<len;i++){
		if(str[i]==' '){
			for(int j=t.size()-1;j>=0;j--)	cout << t[j];
			for(n=0;str[i+n]==' ';n++)	cout << ' ';
			i += n-1;
			t = "";
		}else{
			t.push_back(str[i]);
		}
	}
	for(int i=t.size()-1;i>=0;i--)	cout << t[i];

	return 0;
}


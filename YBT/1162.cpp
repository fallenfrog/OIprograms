#include<iostream>
#include<string>
using namespace std;

void f(string str){
	cout << str[str.length()-2];
	if(str.length()>2){
		str.erase(str.end()-2);
		f(str);
	}
}

int main(){
	string str;
	getline(cin,str);
	f(str);
	return 0;
}

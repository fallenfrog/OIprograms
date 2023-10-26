#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> s;
string str;

int main(){
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		if((str[i]==')'||str[i]==']')&&s.size()==0){
			printf("Wrong");
			return 0;
		}
		if(str[i]=='('||str[i]=='['){
			s.push(str[i]);
		}
		if((str[i]==')'&& s.top()=='(')||(str[i]==']'&&s.top()=='[')){
			s.pop();
		}
	}
	if(s.size()!=0){
		printf("Wrong");
	}else{
		printf("OK");
	}
	
	return 0;
}

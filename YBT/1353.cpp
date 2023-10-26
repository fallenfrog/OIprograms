#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<bool> s;
string str;

int main(){
	getline(cin,str);
	for(int i=0;str[i]!='@';i++){
		if(str[i]==')'&&s.size()==0){
			printf("NO");
			return 0;
		}
		if(str[i]=='('){
			s.push(1);
		}
		if(str[i]==')'){
			s.pop();
		}
	}
	if(s.size()!=0){
		printf("NO");
	}else{
		printf("YES");
	}
	
	return 0;
}

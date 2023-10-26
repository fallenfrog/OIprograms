#include<iostream>
#include<string>
#include<stack>
using namespace std;
string str;
int t;

int main(){
	cin >> t;
	getline(cin,str);
	for(int w=0;w<t;w++){
		bool flag = false;
		stack<int> s;int a;
		getline(cin,str);
		for(int i=0;i<str.length();i++){
			switch(str[i]){
				case '<':a=1;break;
				case '>':a=-1;break;
				case '(':a=2;break;
				case ')':a=-2;break;
				case '[':a=3;break;
				case ']':a=-3;break;
				case '{':a=4;break;
				case '}':a=-4;break;
			}
			if(a<0&&s.size()==0){
				printf("NO\n"); flag=true; break;
			}
			if(a>0&&(s.size()==0||a<=s.top())){
				s.push(a); continue;
			}
			if(a>s.top()){
				printf("NO\n"); flag=true; break;
			}
			if(a==0-s.top()){
				s.pop();
			}
		}
		if(!flag){
			if(s.size()!=0&&s.top()>0){
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}
	}
	
	return 0;
}

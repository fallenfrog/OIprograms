#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#define int long long
using namespace std;
stack<int> s;
string str;
int i;

signed main(){
	getline(cin,str);
	int n=0;
	while(str[i]!='@'){
		char ch=str[i++];
		if(ch==' '){
			s.push(n);
			n=0;
		}else{
			if(ch<58&&ch>47){
				n=n*10+ch-48;
			}else{
				int t1=s.top();s.pop();
				int t2=s.top();s.pop();
				switch(ch){
					case '+':s.push(t2+t1);break;
					case '-':s.push(t2-t1);break;
					case '*':s.push(t2*t1);break;
					case '/':s.push(t2/t1);break;
				}
			}
		}
	}
	cout << s.top();
	
	return 0;
}

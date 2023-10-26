#include<bits/stdc++.h>
#define int long long
using namespace std;
stack<int> nums;
stack<char> ops;
string str;
map<char,int> lev;
int n;

void cal(){
	int a = nums.top();		nums.pop();
	int b = nums.top();		nums.pop();
	char op = ops.top();	ops.pop();
	switch(op){
		case '+':nums.push(b+a);	 break;
		case '-':nums.push(b-a);	 break;
		case '*':nums.push(b*a);	 break;
		case '/':nums.push(b/a);	 break;
		case '^':nums.push(pow(b,a));break;
	}
}

signed main(){
	lev['+'] = lev['-'] = 1;
	lev['*'] = lev['/'] = 2;
	lev['^'] = 3;
	cin >> str;
	for(int i=0;i<str.size();i++){
		char t = str[i];
		if(t>='0' && t<='9'){
			int n = str[i++]-'0';
			while(i<str.size() && str[i]>='0' && str[i]<='9'){
				n = n*10+str[i++]-'0';
			}
			nums.push(n);i--;
		}
		else if(t=='('){
			ops.push(t);
		}
		else if(t==')'){
			while(ops.top()!='('){
				cal();
			}ops.pop();
		}
		else{
			if(!ops.empty() && ops.top()!='(')
				while(!ops.empty() && lev[t]<=lev[ops.top()]){
					cal();
				}
			ops.push(t);
		}
	}	
	while(!ops.empty())	cal();
	cout << nums.top();
	
	return 0;
}

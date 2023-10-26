#include<bits/stdc++.h>
using namespace std;
stack<double> nums;
stack<char> ops;
map<char,int> lev;
string str;
int n,sign = 1;

void cal(){
	double b = nums.top();	nums.pop();
	double a = nums.top();  nums.pop();
	char op = ops.top();ops.pop();
	switch(op){
		case '+':nums.push(a+b);break;
		case '-':nums.push(a-b);break;
		case '*':nums.push(a*b);break;
		case '/':nums.push(a*1.0/b);break;
	}
}

int main(){
	lev['+'] = lev['-'] = 1;
	lev['*'] = lev['/'] = 2;
	cin >> str;
	for(int i=0;str[i]!='@';i++){
		char t = str[i];
		if(t>47 && t<58){
			n = t-'0';n *= sign;sign = 1;
			nums.push(n);
		}
		else if(t=='('){
			ops.push(t);
		}
		else if(t==')'){
			while(ops.top()!='('){
				cal();
			}
			ops.pop();
		}
		else{
			if(t=='-' && (i==0 || str[i-1]=='(')){
				sign = -1;
			}else{
				if(!ops.empty() && ops.top()!='('){
					while(!ops.empty() && lev[t]<=lev[ops.top()]){
						cal();
					}
				}
				ops.push(t);
			}
		}
	}
	while(nums.size()!=1)	cal();
	
	if(ops.size())	cout << "NO";
	else	cout << nums.top();
	
	return 0;
}

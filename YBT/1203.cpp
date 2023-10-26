#include<bits/stdc++.h>
using namespace std;
string s;

struct Ele{
	int idx,c;
};

int main(){
	while(cin>>s){
		stack<Ele> cs;
		for(int i=s.size()-1;i>=0;i--){
			switch(s[i]){
				case ')':cs.push({i,1});break;
				case '(':
					if(!cs.empty() && cs.top().c==1)
						cs.pop();
					else
						cs.push({i,0});
					break;
				default:break;
			}
		}
		cout << s << endl;
		int num = 0;
		while(!cs.empty()){
			Ele t = cs.top();
			if(t.idx==num++){
				switch(t.c){
					case 0:cout << '$';cs.pop();break;
					case 1:cout << '?';cs.pop();break;
				}
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}
	
	return 0;
}

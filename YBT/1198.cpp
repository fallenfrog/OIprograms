#include<bits/stdc++.h>
using namespace std;
string s;

double scan(){
	cin >> s;
	switch(s[0]){
		case '+': return scan()+scan();
		case '-': return scan()-scan();
		case '*': return scan()*scan();
		case '/': return scan()/scan();
		default:  return atof(s.c_str());
	}
}

int main(){
	printf("%f\n", scan());
	
	return 0;
}

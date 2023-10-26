#include<bits/stdc++.h>
using namespace std;
long double a,b,c;
int ic = a-b;

int main(){
	cin >> a >> b;
	c = a-b;
	ic = a-b;
	if(c!=ic){
		cout << "NO";
	}else{
		cout << "YES";
	}
	
	return 0;
}

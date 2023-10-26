#include<bits/stdc++.h>
using namespace std;

int main(){
	double a,b,ans;
	cin >> a >> b;
	ans = a*0.7+b*0.3;
	if(ans>=90) cout << 'A' << endl;
	else{
		if(ans>=80) cout << 'B' << endl;
		else{
			if(ans>=70) cout << 'C' << endl;
			else cout << 'D' << endl;
		}
	}
	
	return 0;
}

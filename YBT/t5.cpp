#include<bits/stdc++.h>
using namespace std;

int main(){
	double n;
	cin >> n;
	if(n>114) cout << "Bike" << endl;
	else{
		if(n==114) cout << "All" << endl;
		else cout << "Walk" << endl;
	}
	
	return 0;
}

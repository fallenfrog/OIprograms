#include<bits/stdc++.h>
using namespace std;
bool win[21] = {0,0,0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,0,0};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(win[n])	cout << "xhgua\n";
		else		cout << "Matrixqwq\n";
	}
	
	return 0;
}

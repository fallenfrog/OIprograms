#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cout << (n%10)*100+(n/10%10)*10+n/100 << endl;
	return 0;
}

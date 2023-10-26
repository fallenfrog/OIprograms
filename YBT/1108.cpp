#include <iostream>
#include <cmath>
using namespace std;
int n,zhiyin,a[1000],k;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> k;
		zhiyin += a[i]*k;
	}
	cout << zhiyin;
	
	return 0;
}

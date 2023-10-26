#include <iostream>
#include <cmath>
using namespace std;
int a[100],n,k;

int main(){
	cin >> n;
	for(int i=n-1;i>=0;i--){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cout << a[i] << ' ';
	}
	
	return 0;
}

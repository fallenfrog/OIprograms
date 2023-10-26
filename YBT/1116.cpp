#include<iostream>
using namespace std;
int n,maxx,a[100000],len;

int main(){
	cin >> n;
	a[0] = 0x7fffffff;
	for(int i=1;i<n+1;i++){
		cin >> a[i];
		if(a[i]==a[i-1]) len++;
		else len = 1;
		if(len>maxx) maxx=len;
	}
	
	cout << maxx;
	
	return 0;
}

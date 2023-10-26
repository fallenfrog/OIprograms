#include<iostream>
using namespace std;
int m,n,maxx=-10000,minn=10000;


int main(){
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> n;
		if(n>maxx) maxx = n;
		if(n<minn) minn = n;
	}
	cout << maxx-minn;
	
	return 0;
} 

#include<iostream>
using namespace std;
int a[100],n,i=0;

int main(){
	while(cin>>a[i++])
	{
		n++;
	}
	for(int j=n-1;j>=0;j--){
		cout << a[j] << ' ';
	}
	return 0;
} 

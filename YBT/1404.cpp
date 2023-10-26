#include<iostream>
using namespace std;
int n,sum;

int main(){
	cin >> n;
	for(int i=1;i<=100000;i++){
		sum = i*(i+1)/2;
		for(int j=1;j<=i;j++){
			if(sum-3*j==n){
				cout << j << ' ' << i;
				return 0; 
			}
		}
	}
	
	return 0;
}

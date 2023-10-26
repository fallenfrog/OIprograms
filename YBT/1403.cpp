#include<iostream>
#include<cmath>
using namespace std;
int n;

bool ss(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin >> n;
	for(int i=3;i<=n;i+=2){
		if(ss(i)&&ss(i+2)){
			cout << i << ' '  << i+2 << endl;
		}
	}
	
	return 0;
}

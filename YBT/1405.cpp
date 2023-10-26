#include<iostream>
#include<cmath>
using namespace std;
int n,mass,maxx;

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
	for(int i=2;i<=n/2;i++){
		if(ss(i)&&ss(n-i)){
			mass = i*(n-i);
		}
		if(mass>maxx) maxx = mass;
	}
	cout << maxx;
	
	return 0;
}

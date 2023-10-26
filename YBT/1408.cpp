#include<iostream>
#include<cmath>
using namespace std;

int cnt,n;

bool prime(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

bool hw(int a){
	int b=0,m=a;
	while(m>0){
		b = 10*b+m%10;
		m = m/10;
	}
	if(b==a) return true;
	else return false;
}

int main(){
	cin >> n;
	for(int i=11;i<=n;i++){
		if(prime(i)&&hw(i)){
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

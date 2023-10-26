#include<iostream>
#include<cmath>
using namespace std;
int m,cnt;
bool isp[50005];

int isprime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(!isp[i]){
			for(int j=2;i*j<=n;j++){
				isp[j*i] = 1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(!isp[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

int main(){
	cin >> m;
	isprime(m);
	
	return 0;
} 

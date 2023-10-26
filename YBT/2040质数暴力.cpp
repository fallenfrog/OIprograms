#include <iostream>
#include <cmath>
using namespace std;
int a[20],n,k;

bool zhishu(int num){
	bool sign = true;
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0&&num!=2) sign = false;
	}
	return sign;
}

int main(){
	cin >> n;
	for(int i=2;i<=n;i++){
		if(zhishu(i)) cout << i << endl;
	}
	
	return 0;
}

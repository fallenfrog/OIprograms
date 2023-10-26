#include <iostream>
using namespace std;
int a[1001],n;

struct num{
	int data,p;
}k;

int main(){
	cin >> n;
	cin >> a[0];
	k.data = a[0];k.p = 0;
	for(int i=1;i<n;i++){
		cin >> a[i];
		if(k.data<a[i]){
			k.data=a[i];
			k.p=i;
		}
	}
	cout << k.p+1;
	return 0;
}

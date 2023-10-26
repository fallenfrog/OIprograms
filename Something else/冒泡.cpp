#include <iostream>
using namespace std;
int a[2000000],n,k;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		bool flag = 1;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
				flag = 0;
			}
		}
		if(flag) break;
	}
	for(int i=0;i<n;i++){
		cout << a[i];
	} 
	
	return 0; 
}

#include <iostream>
using namespace std;
int a[20],n,k;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cout << a[n-1] << endl;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(a[j]>a[j+1]){
				k = a[j+1];
				a[j+1] = a[j];
				a[j] = k;
			}
		}
		cout << a[i+1] << endl; 
		
	}
	
	return 0;
}

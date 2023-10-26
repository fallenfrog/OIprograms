#include<iostream>
using namespace std;
int a[100005],n,t;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[(j+1)*(i+1)-1] = 1-a[(j+1)*(i+1)-1];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==1){
			cout << i+1 << ' ';
		}
	}
	
	return 0;
} 

#include<iostream>
using namespace std;
int m,n,a[20][20];

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(i==j||i+j==n-1){
				a[i][j] += 10;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

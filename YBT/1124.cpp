#include<iostream>
using namespace std;
int m,n,a1[100][100],sum[100][100];

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a1[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> sum[i][j];
			sum[i][j] += a1[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << sum[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

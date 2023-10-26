#include<iostream>
using namespace std;
int m,n,a1[100][100],a2[100][100];

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a1[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a2[j][i] = a1[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << a2[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

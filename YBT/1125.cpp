#include<iostream>
using namespace std;
int m,n,k,a1[100][100],a2[100][100],zhiyin[100][100];

int main(){
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a1[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			cin >> a2[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			for(int h=0;h<m;h++){
				zhiyin[i][j] += a1[i][h]*a2[h][j];
			}
			cout << zhiyin[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

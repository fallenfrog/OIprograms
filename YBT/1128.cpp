#include<iostream>
using namespace std;
int m,n,a1[100][100],a2[100][100];
double k;

int sishewuru(double n){
	if(n-(int)(n)>=0.5) return (int)(n)+1;
	else return (int)(n);
} 

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a1[i][j];
		}
	}
	
	for(int i=0;i<n;i++) a2[i][0] = a1[i][0];
	for(int i=0;i<n;i++) a2[i][m-1] = a1[i][m-1];
	for(int i=0;i<m;i++) a2[0][i] = a1[0][i];
	for(int i=0;i<m;i++) a2[n-1][i] = a1[n-1][i];
	
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			a2[i][j] = sishewuru((a1[i][j]+a1[i-1][j]+a1[i][j+1]+a1[i][j-1]+a1[i+1][j])*1.0/5);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << a2[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

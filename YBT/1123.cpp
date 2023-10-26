#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int m,n,same,difference;
char i1[100][100],i2[100][100];

int main(){
	cin >> m >> n;
	int tot = m*n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> i1[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> i2[i][j];
			if(i2[i][j]==i1[i][j]){
				same++;
			}
		}
	}	
	printf("%.2lf",same*1.0/tot*100);
	return 0;
}

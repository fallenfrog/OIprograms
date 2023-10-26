#include<bits/stdc++.h>
using namespace std;
int m,n;
int s[11][11];

int main(){
	for(int i=1;i<11;i++){
		s[0][i] = 1;
	}
	for(int i=1;i<11;i++){
		s[i][1] = 1;
		for(int j=2;j<11;j++){
			if(j>i){
				s[i][j] = s[i][i];
			}else{
				s[i][j] = s[i][j-1]+s[i-j][j];
			}
		}
	}
	
	int t;cin >> t;
	while(t--){
		cin >> m >> n;
		cout << s[m][n] << endl;
	}
	
	return 0;
} 

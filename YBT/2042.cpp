#include<iostream>
using namespace std;
int t,m,n,a[100][100],ans[1000][3];

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
			if(a[i][j]){
				ans[t][0] = i+1;
				ans[t][1] = j+1;
				ans[t][2] = a[i][j];
				t++;
			}
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

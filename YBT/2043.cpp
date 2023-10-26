#include<iostream>
using namespace std;
int t,m,n,a[20][20];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(j==0||j==i-1){
				a[i-1][j] = 1;
			}
			else{
				a[i-1][j] = a[i-2][j]+a[i-2][j-1];
			}
			cout << a[i-1][j] << ' ';
		}
		cout << endl;
	}
//	for(int i=0;i<t;i++){
//		for(int j=0;j<3;j++){
//			cout << ans[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	return 0;
}

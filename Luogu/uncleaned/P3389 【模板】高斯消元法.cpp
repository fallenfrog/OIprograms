#include<bits/stdc++.h>
using namespace std;
int n;
double m[102][102],ans[102];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			cin >> m[i][j];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			double t = m[j][i]/m[i][i];	m[j][i] = 0;
			for(int k=i+1;k<=n+1;k++){
				m[j][k] -= t*m[i][k];
			}
			bool ok = 0;
			for(int k=i+1;k<=n+1;k++){
				if(m[j][k]!=0)	ok = 1;
			}
			if(!ok){
				cout << "No Solution";
				return 0;
			}
		}
	}
	for(int i=n;i>0;i--){
		for(int j=i+1;j<=n;j++){
			m[i][n+1] -= m[i][j]*ans[j];
		}
		ans[i] = m[i][n+1]/m[i][i];
	}
	for(int i=1;i<=n;i++)	printf("%.2lf\n",ans[i]);

	return 0;
}


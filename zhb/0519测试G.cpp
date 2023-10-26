#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,cnt,ans=INF;
int mov[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
bool s[20][20],ls[20][20];

void fz(int x,int y){
	for(int i=0;i<5;i++){
		int tx = x+mov[i][0],ty = y+mov[i][1];
		if(tx>=0 && tx<m && ty>=0 && ty<n)
			ls[tx][ty] = !ls[tx][ty];
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			char t;	cin >> t;
			if(t=='X')	s[j][i] = 1;
			if(t=='.')	s[j][i] = 0;
		}
	int tot = 1<<m;
	for(int zp=0;zp<tot;zp++){
		cnt = 0;
		bool flag = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ls[j][i] = s[j][i];
		for(int i=0,k=zp;k>0;k>>=1,i++){
			if(k&1){
				cnt++;
				fz(i,0);
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=0;j<m;j++){
				if(ls[j][i-1]){
					cnt++;
					fz(j,i);
				}
			}
		}
		for(int i=0;i<m;i++){
			if(ls[i][n-1]){
				flag = 1;
				break;
			}
		}
		if(!flag)	ans = min(ans,cnt);
	}
	cout << ans;
	
	return 0;
}

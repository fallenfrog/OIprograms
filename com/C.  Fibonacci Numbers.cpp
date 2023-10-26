#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
struct Matrix{
	int l,w,num[5][5];
	Matrix(int tl=3,int tw=3){l = tl,w = tw;}
	Matrix operator *(const Matrix& other)const{
		Matrix ans(l,other.w);
		for(int i=1;i<=l;i++){
			for(int j=1;j<=other.w;j++){
				ans.num[i][j] = 0;
				for(int k=1;k<=w;k++){
					ans.num[i][j] += num[i][k] * other.num[k][j];
					ans.num[i][j] %= mod;
				}
			}
		}
		return ans;
	}
}p,a(3,1);
long long n;

signed main(){
	cin >> n;
	p.num[1][1] = p.num[2][1] = p.num[3][1] = p.num[2][2] = p.num[1][3] = 0;
	p.num[1][2] = p.num[2][3] = p.num[3][2] = p.num[3][3] = 1;
	a.num[1][1] = a.num[2][1] = 0,a.num[3][1] = 1;
	for(;n;n>>=1){
		if(n&1)	a = p*a;
		p = p*p;
	}
	cout << a.num[2][1];
	
	return 0;
}

#include<bits/stdc++.h>
#define i8 __int128
//#define int long long
using namespace std;
long long m,a,c,x0,n,g;
struct Matrix{
	i8 num[2][2];
	Matrix(i8 a=0,i8 b=0,i8 c=0,i8 d=0){num[0][0]=a,num[0][1]=b,num[1][0]=c,num[1][1]=d;}
	Matrix operator *(const Matrix& other)const{
		Matrix ans;
		ans.num[0][0] = (num[0][0]*other.num[0][0]+num[0][1]*other.num[1][0])%m;
		ans.num[0][1] = (num[0][0]*other.num[0][1]+num[0][1]*other.num[1][1])%m;
		ans.num[1][0] = (num[1][0]*other.num[0][0]+num[1][1]*other.num[1][0])%m;
		ans.num[1][1] = (num[1][0]*other.num[0][1]+num[1][1]*other.num[1][1])%m;
		return ans;
	}
};

int main(){
	cin >> m >> a >> c >> x0 >> n >> g;
	i8 t = x0;
	Matrix ans(x0,1,t*a,1),p(a,0,c,1);
	for(;n;n>>=1){
		if(n&1)	ans = ans*p;
		p = p*p;
	}
	cout << (long long)ans.num[0][0]%g;

	return 0;
}


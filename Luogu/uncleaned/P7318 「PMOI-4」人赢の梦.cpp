#include<bits/stdc++.h>
using namespace std;
long long k;
int n,m,a[30];

int main(){
	cin >> n >> m >> k;
	if(k<3){
		if(k==1)	cout << n;
		if(k==2)	cout << m;
		return 0;
	}
	k -= 3;
	a[0] = n*m%10;
	a[1] = a[0]*m%10;
	for(int i=2;i<6;i++)	a[i] = a[i-1]*a[i-2]%10;
	cout << a[k%6];

	return 0;
}


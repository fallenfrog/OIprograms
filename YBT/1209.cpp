#include<bits/stdc++.h>
using namespace std;
struct fs{
	int a,b;
	fs(int x,int y){a=x,b=y;}
	
	fs operator +(fs x){
		int k = b*x.b/__gcd(b,x.b);
		a *= k/b;	x.a *= k/x.b;
		a += x.a;	b = k;
		int t = __gcd(a,b);
		a /= t;	b /= t;
		return {a,b};
	}
}ans(0,1);
int n;

int main(){
	cin >> n;
	fs t(0,1);
	for(int i=1;i<=n;i++){
		scanf("%d/%d",&t.a,&t.b);
		ans = ans + t;
	}
	cout << ans.a;
	if(ans.b!=1)	cout << '/' << ans.b;
	
	return 0;
}

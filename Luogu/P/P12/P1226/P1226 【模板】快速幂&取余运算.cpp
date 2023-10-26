#include<cstdio>
#define int long long
using namespace std;
int a,b,p;

int f(int a,int b,int p){
	int result=1;
	while(b>0){
		if(b&1){
			result = result*a%p;
		}
		b >>= 1;
		a = (a*a)%p;
	}
	
	return result;
}

signed main(){
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=%lld",a,b,p,f(a,b,p));
	
	return 0;
}

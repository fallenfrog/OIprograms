#include<cstdio>
using namespace std;

int main(){
	long long n,p,k;
	scanf("%lld%lld%lld",&n,&p,&k);
	printf("%lld",p*k%n);
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	double a,b;
	cin >> a >> b;
	int i;
	for(i=0;a>=0;i++){
		a -= b;
	}
	printf("%.2lf\n",a+b);
	
	return 0;
}

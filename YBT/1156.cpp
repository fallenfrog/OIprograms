#include<iostream>
#include<cmath>
using namespace std;
double pi;int i=1;

double arctanx(double x){
	double ans = 0,temp = x;
	
	while(abs(temp/i)>=1E-6){
		ans += temp/i;
		temp = temp*x*x*-1;
		i += 2;
	}
	return ans;
}

double arctan(double x){
	double ans = 0,m = 1;
	
	while(abs(m)>=1E-6){
		m = pow(x,i)/i*pow(-1,i/2);
		ans += m;
		cout << ans << endl;
		i += 2;
	}
	return ans;
}

int main(){
	double x = 1/sqrt(3);
	pi = 6*arctanx(x);
	printf("%.10lf",pi);
	return 0;
} 

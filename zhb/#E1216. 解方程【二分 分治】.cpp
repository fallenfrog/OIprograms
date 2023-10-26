#include<bits/stdc++.h>
#define double long double
#define W 1e-4
using namespace std;
int a = 8,b = 7,c = 2,d = 3,e = 6;
int T;
bool flag;

double f(double x,double e){
	return a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
}

bool check(double x,double e){
	return f(x,e)>0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> T;
	int f0 = 6,f100 = 807020306;
	while(T--){
		double y;
		cin >> y;
		if(y<f0 || y>f100){
			printf("No solution!\n");
			continue;
		}
		double te = e-y;
		double l = 0,r = 100;
		for(int i=1;i<=10000;i++){
			double mid = (l+r)/2;
			if(check(mid,te)){
				r = mid;
			}else{
				l = mid;
			}
		}
		printf("%.4Lf\n",l);
	}
	
	return 0;
}

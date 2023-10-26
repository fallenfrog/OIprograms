#include<iostream>
#include<cmath>
using namespace std; 
int n,cnt,sum,a;


int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		cnt += ceil(a*1.0/70);
	}
	printf("%.1lf",cnt*0.1);
	return 0;
}

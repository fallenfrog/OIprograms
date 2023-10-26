#include<iostream>
using namespace std;
double a[300],sum,aver;
int n;
bool flag = true;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	
	for(int i=n-1;i>0;i--){
		flag = false;
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag = true;
			}
		}
		if(!flag) break;
	}
	
	aver = (sum-a[0]-a[n-1])/(n-2);
	printf("%.2lf %.2lf",aver,a[n-2]-aver>aver-a[1]?a[n-2]-aver:aver-a[1]);
	
	return 0;
}

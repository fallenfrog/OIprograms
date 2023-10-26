#include <iostream>
#include <cmath>
using namespace std;
int tot,k,a,b,c,d;

int main(){
	cin >> tot;
	for(int i=0;i<tot;i++){
		cin >> k;
		if(k<19) a++;
		if(k<36&&k>18) b++;
		if(k<61&&k>35) c++;
		if(k>60) d++;
	}
	printf("%.2lf%%\n",a*1.0/tot*100);
	printf("%.2lf%%\n",b*1.0/tot*100);
	printf("%.2lf%%\n",c*1.0/tot*100);
	printf("%.2lf%%\n",d*1.0/tot*100);
	
	return 0;
}

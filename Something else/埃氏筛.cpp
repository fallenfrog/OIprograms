#include<iostream>
#include<cmath>
using namespace std;
#define L 114514
bool isp[L];

int main(){
	int cnt=0;
	for(int i=2;i<L;i++){
		if(!isp[i]){
			for(int j=2;j*i<=L;j++){
				isp[i*j] = 1;
			}
			cout << i << " ";cnt++;
		}
	}
	cout << endl << cnt;
	
	return 0;
}

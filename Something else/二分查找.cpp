#include<bits/stdc++.h>
using namespace std;
int q[10000],a,cnt=0;

int halfind(int a,int h,int t){
	if(h>t) return -1;
	int temp = (h+t)/2;
	cnt++;
	if(q[temp]==a) return temp;
	if(q[temp]>a){
		return halfind(a,h,temp);
	}
	if(q[temp]<a){
		return halfind(a,temp,t);
	}
}

int main(){
	for(int i=1;i<=10000;i++){
		q[i-1] = i;
	}
	cin >> a;
	cout << halfind(a,0,9999);
	cout << ' ' << cnt;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,num[1001];

int get(int x){
	if(num[x]!=0)	return num[x];
	num[x] = 1;
	for(int i=1;i<=x/2;i++){
		num[x] += get(i);
	}
	return num[x];
}

int main(){
	num[1] = 1;
	cin >> n;
	cout << get(n);
	
	return 0;
}

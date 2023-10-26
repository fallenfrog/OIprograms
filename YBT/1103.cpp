#include<iostream>
using namespace std;
int a[10],h,num;

int main(){
	for(int i=0;i<10;i++){
		cin >> a[i];
	}
	
	cin >> h;
	for(int i=0;i<10;i++){
		if(h+30>=a[i]){
			num++;
		}
	}
	cout << num;
	
	return 0;
} 

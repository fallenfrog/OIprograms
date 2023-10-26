#include<iostream>
using namespace std;
int n,m;

struct Day{
	int data,num;
}t;

int main(){
	for(int i=0;i<7;i++){
		cin >> n >> m;
		if(t.data<n+m){
			t.data = n+m;
			t.num = i;
		}
	} 
	if(t.data>8){
		cout << t.num+1;
	}
	else{
		cout << 0;
	}
	
	return 0;
} 

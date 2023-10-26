#include<iostream>
using namespace std;

char num_chan(int n){
	if(n<10) return (char)(n+48);
	else return (char)(n+55);
}

void change(int n,int m){
	if(n<m) cout << num_chan(n);
	else{
		change(n/m,m);
		change(n%m,m);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	change(n,m);
	return 0;
}

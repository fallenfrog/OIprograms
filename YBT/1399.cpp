#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int cnt,n;
string py[200];

struct Patient{
	string name;
	double tem;
	int cough;
	
	void shaicha(int i){
		if(tem>=37.5&&cough){
			py[cnt] = name;
			cnt++;
		}
	} 
}p[200];

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p[i].name >> p[i].tem >> p[i].cough;
		p[i].shaicha(i);
	}
	for(int i=0;i<cnt;i++){
		cout << py[i] << endl; 
	}
	cout << cnt;
	
	return 0;
}

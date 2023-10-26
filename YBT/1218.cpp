#include<bits/stdc++.h>
using namespace std;
int a,b;
bool step;

int main(){
	while(cin>>a>>b){
		if(a==b && a==0)	return 0;
		step = 0;
		if(a<b)	swap(a,b);
		while(a%b!=0 && a<2*b){
			step = !step;
			a -= b;
			swap(a,b);
		}
		if(step)	cout << "lose\n";
		else		cout << "win\n";
	}
	
	return 0;
}

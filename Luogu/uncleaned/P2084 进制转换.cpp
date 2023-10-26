#include<iostream>
#include<string>
using namespace std;
int m,i;
string str,n;

int main(){
	cin >> m >> n;
	while(i<n.size()){
		int t=n[i++]-'0';
		if(t!=0){
			if(i==1)
				printf("%d*%d^%d",t,m,n.size()-i);
			else
				printf("+%d*%d^%d",t,m,n.size()-i);
		}
	}
	
	return 0;
}

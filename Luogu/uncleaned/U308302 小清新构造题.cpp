#include<bits/stdc++.h>
using namespace std;
int n,k;

int main(){
	cin >> n >> k;
	if(n==1){
		cout << "No";
		return 0;
	}
	printf("Yes\n");
	if(n==3){
		printf("6 1\n2 3\n4 5\n1 1\n5 0");
	}
	if(n==5 && k==7){
		printf("8 5\n3 3\n7 0\n10 1\n9 9\n7 0\n6 4\n2 2\n7 0");
	}
	if(n==k){
		for(int i=1;i<n;i++)	printf("%d %d\n",i,i+n);
		printf("%d %d\n%d %d\n%d 0\n",2*n,n,n,n,n);
		for(int i=2;i<=n-3;i+=2)	printf("%d %d\n%d 0\n",n,n,n);
		return 0;
	}
	if(n>5 && k&1){
		for(int i=2;i<k;i+=2){
			printf("%d %d\n",i,i+1);
		}
		for(int i=k+2;i<n*2;i+=2){
			printf("%d %d\n",i,i+1);
		}
		for(int i=1;i<n;i+=2){
			printf("1 1\n1 0\n");
		}
		printf("%d 1",k+1,1);
	}
	
	return 0;
}

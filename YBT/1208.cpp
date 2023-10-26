#include<bits/stdc++.h>
using namespace std;
int n;

void print(int n,bool flag){
	int t;
	for(int i=16;n>0;i--){
		t = 1<<i;
		if(n>=t){
			n -= t;
			if(flag){
				printf("+");
			}
			printf("2");
			flag = 1;
			if(i!=1){
				if(i==2 || i==0)	printf("(%d)",i);
				else{
					printf("(");
					print(i,0);
					printf(")");
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	print(n,0);
	
	return 0;
}

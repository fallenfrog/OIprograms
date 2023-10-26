#include<bits/stdc++.h>
using namespace std;
int n;
char l,m,r;

void hinor(int top,int n,char l,char m,char r){
	if(n==1){
		printf("%c->%d->%c\n",l,top,r);
		return ;
	}
	hinor(top,n-1,l,r,m);
	printf("%c->%d->%c\n",l,n,r);
	hinor(top,n-1,m,l,r);
}

int main(){
	cin >> n >> l >> m >> r;
	hinor(1,n,l,r,m);
	
	return 0;
}

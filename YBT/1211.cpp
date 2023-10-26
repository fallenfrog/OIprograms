#include<bits/stdc++.h>
using namespace std;
int k,x;
bool flag;

void dfs(int x){
	if(x==k){
		flag = 1;
		cout << "YES";
		return ;
	}
	x--;
	if(x<0)	return ;
	for(int i=2;i<4;i++){
		int t = x;
		if(t%i==0){
			t /= i;
			dfs(t);
			if(flag){
				return ;
			}
		}
	}
}

int main(){
	scanf("%d,%d",&k,&x);
	dfs(x);
	if(!flag)	cout << "NO";
	
	return 0;
}

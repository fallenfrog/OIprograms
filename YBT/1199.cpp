#include<iostream>
#include<cstring>
using namespace std;
char s[10],t[10];
bool vis[10];
int len;

void print(int cnt){
	if(cnt==len){
		t[cnt] = '\0';
		printf("%s\n",t);
		return;
	}
	for(int i=0;i<len;i++){
		if(!vis[i]){
			t[cnt] = s[i];
			vis[i] = 1;
			print(cnt+1);
			vis[i] = 0;
		}
	}
}

int main(){
	scanf("%s",s);
	len = strlen(s);
	print(0);
	
	return 0;
}
//什么傻逼题目
//用个万能头都给错
//真该把出题人的头丢去装大粪 

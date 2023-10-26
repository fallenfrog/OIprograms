#include<iostream>
#include<cstdio>
using namespace std;
int chess[14],heng[14],shu[14],zuodui[26],youdui[26];
int n,cnt;
void print();
void dfs(int x);

int main(){
	n=8;
	dfs(1);
	
	return 0;
}

void dfs(int x){
	if(x==n+1){
		print();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!(heng[i]||shu[i]||zuodui[x+i-1]||youdui[x-i+n])){
			chess[x] = i;
			heng[i]=shu[i]=zuodui[x+i-1]=youdui[x-i+n]=1;
			dfs(x+1);
			chess[x] = 0;
			heng[i]=shu[i]=zuodui[x+i-1]=youdui[x-i+n]=0;
		}
	}
}

void print(){
	cnt++;
	printf("No. %d\n",cnt);
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(i==chess[j]){
				printf("%d ",1);
			}else{
				printf("%d ",0);
			}
		}
		printf("\n");
	} 
}

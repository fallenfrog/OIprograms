#include<iostream>
#include<cstdio>
using namespace std;
int board[14],heng[14],shu[14],zuodui[26],youdui[26];
int n,cnt;
void print();
void dfs(int x);

int main(){
	cin >> n;
	dfs(1);
	cout << cnt;
	
	return 0;
}

void dfs(int x){
	if(x==n+1){
		print();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!(heng[i]||shu[i]||zuodui[x+i-1]||youdui[i-x+n])){
			board[x] = i;
			heng[i]=shu[i]=zuodui[x+i-1]=youdui[i-x+n]=1;
			dfs(x+1);
			board[x] = 0;
			heng[i]=shu[i]=zuodui[x+i-1]=youdui[i-x+n]=0;
		}
	}
}

void print(){
	if(cnt<3){
		for(int i=1;i<=n;i++){
			printf("%d ",board[i]);
		}
		printf("\n");
	}
	cnt++;
}

#include<bits/stdc++.h>
using namespace std;
int t,k,n,queen[92];
bool sl[9],zx[16],yx[16];

void dfs(int x){
	if(x>8){
		queen[k++] = t;
		return ;
	}
	for(int i=1;i<9;i++){
		if(!sl[i] && !zx[8-i+x] && !yx[x+i-1]){
			sl[i] = zx[8-i+x] = yx[x+i-1] = 1;
			t = t*10+i;
			dfs(x+1);
			sl[i] = zx[8-i+x] = yx[x+i-1] = 0;
			t = (t-1)/10;
		}
	}
}

int main(){
	dfs(1);
	sort(queen,queen+92);
	cin >> n;
	while(n--){
		cin >> t;
		cout << queen[t-1] << '\n';
	}
	
	return 0;
}

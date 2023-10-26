#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> dp[1001];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		dp[i].push_back(0);
		for(int j=1;j<=i;j++){
			int t;
			scanf("%d",&t);
			dp[i].push_back(t);
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=i;j>0;j--){
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
		}
	}
	printf("%d",dp[1][1]);
	
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int m,n,p,cnt,t,dp[201];

struct item{
	int c,v;
};
vector<item> it[11];

int main(){
	scanf("%d%d%d",&m,&n,&p);
	for(int i=0;i<n;i++){
		item e;int belong;
		scanf("%d%d%d",&e.c,&e.v,&belong);
		it[belong].push_back(e);
	}
	
	for(int i=1;i<=p;i++){
		printf("---------��%d��---------\n",i);
		for(int j=m;j>=0;j--){
			for(int k=0;k<it[i].size();k++){
				if(j>=it[i][k].c){
					dp[j] = max(dp[j],dp[j-it[i][k].c]+it[i][k].v);
					printf("���%d,����Ϊ%d�ı�������װ%d����Ʒ\n",k+1,j,dp[j]);
				}
			}
		}
	}
	printf("%d",dp[m]);
	
	return 0;
}

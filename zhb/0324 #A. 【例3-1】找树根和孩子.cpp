#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,u,v,parent[101],degree[101];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		parent[v] = u;
		degree[u]++;
	}
	int maxn=1;
	for(int i=1;i<=n;i++){
		if(parent[i]==0){
			printf("%d\n",i);
		}
		if(degree[maxn]<degree[i]){
			maxn = i;
		}
	}
	printf("%d\n",maxn);
	for(int i=1;i<=n;i++){
		if(parent[i]==maxn){
			printf("%d ",i);
		}
	}
	
	return 0;
}

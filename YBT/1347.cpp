#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,parent[40001],depth[40001];

int find(int x){
	if(parent[x]!=x) parent[x]=find(parent[x]);
	return parent[x];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*n;i++){
		parent[i] = i;
	}
	for(int i=0;i<m;i++){
		int x,y,p1,p2;char ch;
		scanf("%d %d %c",&y,&x,&ch);
		p1 = (y-1)*n+x;
		if(ch=='R') p2 = p1+1;
		else p2 = p1+n;
		int f1 = find(p1),f2 = find(p2);
		if(f1==f2){
			printf("%d",i+1);
			return 0;
		}
		if(depth[f1]>depth[f2]){
			parent[f2] = f1;
		}else{
			parent[f1] = f2;
			depth[f1] = max(depth[f1],depth[f2]+1);
		}
	}
	printf("draw");
	return 0;
}

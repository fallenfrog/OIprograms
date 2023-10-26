#include<bits/stdc++.h>
using namespace std;
int n,h[301],sr[301],tr[301];
long double A[300][300];

void init(int n){
	for(int i=0;i<=n;i++){
		A[0][i] = 1;
		for(int j=1;j<=i;j++){
			A[j][i] = A[j-1][i]*(i-j+1);
		}
	}
	for(int i=1;i<=n;i++){
		sr[i] = i-1,tr[i] = n-i;
		for(int j=i+1;j<=n;j++){
			if(h[j]!=h[i])	break;
			sr[i]++;tr[i]--;
		}
		if(tr[i]==0)	tr[i] = 1;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",h+i);
	sort(h+1,h+n+1);
	init(n);
	
	long double sum = 0;
	for(int i=1;i<=n;i++){
		printf("\n\n\n-----------位置%d------------",i);
		
		for(int j=1;j<=n;j++){
			printf("\n-----第%d个人-----\n\n",j);
			for(int l=1;l<=i;l++){
				printf("-----距离%d-----\n",l);
				printf("A(%d %d)=%.0Lf   总期望%.0Lf",l-1,sr[j],A[l-1][sr[j]],sum);
				sum += l*tr[j]*A[l-1][sr[j]];
				printf("+%.0Lf=%.0Lf\n",l*tr[j]*A[l-1][sr[j]],sum);
			}
		}
	}
	printf("总：%.0Lf\n",sum);
	sum /= A[n-1][n];
	printf("%.2Lf",sum);
	
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100001],cnt;
void quicksort(int i,int j){
	if(i>=j) return ;
	int t=a[i],ti=i,tj=j;
	while(ti<tj){
		while(a[tj]>=t&&ti<tj) tj--;
		while(a[ti]<=t&&ti<tj) ti++;
		if(ti!=tj){
			swap(a[ti],a[tj]);
			cnt++;
		}
	}
	if(ti!=i){
		swap(a[ti],a[i]);
		cnt++;
	}
	quicksort(i,ti-1);
	quicksort(ti+1,j);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	quicksort(0,n-1);
	printf("%d",cnt);
	
	return 0;
}

#include<cstdio>
using namespace std;
int n,m,t,a[200000],ans[20000];

int halfind(int x){
	int h=1,t=n,mid;
	while(h<t){
		mid=h+(t-h)/2;
		if(a[mid]>=x){
			t = mid;
		}else{
			h = mid+1;
		}
	}
	if(a[h]==x){
		return h;
	}else{
		return -1;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){//��0��ʼ��������Ҫ+1
		scanf("%d",a+i);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&t);
		printf("%d ",halfind(t));
	}
	
	return 0;
}

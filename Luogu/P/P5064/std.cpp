#include <bits/stdc++.h>
#define rg register
using namespace std;
inline int read(){
	int s = 0,f = 1;char c = getchar();
	while (!isdigit(c)){if (c == '-')f = -1;c = getchar();}
	while (isdigit(c)){s = (s << 3) + (s << 1) + (c ^ 48);c = getchar();}
	return s*f;
}
const int N = 1e5 + 3;
const int block = 3000;
int n,m,k;
int a[N],b[N];
int size[N],f[N],num[N];
short bucket[N][N / block + 2];
int number[N];
struct node{
	int opt,x,y;
}q[N];
int head[N];
struct edge{
	int v,next;
}tree[N];
int ans[N],cnt;
void add(int u,int v){
	tree[++cnt].next = head[u];
	tree[cnt].v = v;
	head[u] = cnt;
}//链式前向星
int find(int x){
	if (f[x] == x)
	    return x;
	return find(f[x]);
}//不要写路径压缩！
void dfs(int u){
	int opt = q[u].opt,x = q[u].x,y = q[u].y;
	int fatherx = 0,fathery = 0;
	if (opt != 2)    fatherx = find(x),fathery = find(y);
	if (opt == 1)//普通的加边操作
		if (fatherx != fathery){
			if (size[fatherx] > size[fathery])    swap(fatherx,fathery);
			f[fatherx] = fathery;    size[fathery] += size[fatherx];
			for (rg int i=1;i<=k;++i)    bucket[fathery][i] += bucket[fatherx][i];
		}
	if (opt == 3){//操作3,注释见上
		if (y > size[fatherx])    ans[u] = -1;
		else {
			for (rg int i=1;i<=k;++i){
				if (y <= bucket[fatherx][i]){
					for (rg int j = (i - 1) * block + 1;j <= i * block;++j)
						if (find(num[j]) == fatherx){
							--y;
							if (y == 0){
								ans[u] = b[j];
								break;
							}
						}
					break;
				}
				y -= bucket[fatherx][i];
			}
		}
	}
	for (rg int i=head[u];i;i=tree[i].next)    dfs(tree[i].v);
    //遍历所有可能操作
	if (opt == 1 && fatherx != fathery){
    //注意，这里是一个易错点
    //为什么要写 fatherx != fathery 呢？
    //如果在建边之前，x和y已经在同一个联通块中，那么这个联通块就不需要被建立
    //同理，由于x和y已经在同一个联通块中，则必然其父节点的状态中，x和y也在同一个联通块中。
    //所以不需要进行回溯
		size[fathery] -= size[fatherx];    f[fatherx] = fatherx;
		for (int i=1;i<=k;++i)    bucket[fathery][i] -= bucket[fatherx][i];
	}
}
int main()
{
    n = read();m = read();
    k = (n-1) / block + 1;
    for (rg int i=1;i<=n;++i){
    	f[i] = i;size[i] = 1; //朴素的初始化
    	b[i] = a[i] = read(); 
	}
	sort(b+1,b+n+1);
	for (rg int i=1;i<=n;++i){
		a[i] = lower_bound(b+1,b+n+1,a[i]) - b;//离散化数组
		a[i] += number[a[i]]++;   //注意，同一个数的离散化值应不一样。
        num[a[i]] = i;
		bucket[i][(a[i] - 1) / block + 1] = 1;
	}
	for (rg int i=1;i<=m;++i){
		q[i].opt = read();q[i].x = read();
		if (q[i].opt != 2)q[i].y = read(),add(i-1,i);
		if (q[i].opt == 2)	add(q[i].x,i);
	}
	dfs(0);
	for (rg int i=1;i<=m;++i)   
	    if (q[i].opt == 3) printf("%d\n",ans[i]);
	return 0;
}
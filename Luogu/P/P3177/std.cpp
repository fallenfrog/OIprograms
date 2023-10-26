#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 2005;

struct Edge{
    int x, y, w, nxt;
}e[maxn << 1 | 1];

int n, m, cnt;
int fr, to, haj;

int head[maxn], siz[maxn];

long long f[maxn][maxn];

inline int read(void)
{
    int s = 0, w = 1;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
    for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
    return s * w;
}

inline void add(int x, int y, int w)
{
    e[++cnt].x = x;
    e[cnt].y = y;
    e[cnt].w = w;
    e[cnt].nxt = head[x];
    head[x] = cnt;  
}

void dfs(int x, int father)
{
    siz[x] = 1; // 初始化子树的大小，因为有本身这个点，所以大小赋值为 1  
    f[x][0] = f[x][1] = 0; // 无论在什么情况下，不选和只选一个这两种情况一定合法，所以把值赋成 0，在下面更新 
    for(register int i = head[x]; i != -1; i = e[i].nxt)
    {
        int y = e[i].y;
        if(y == father) continue; // 加边加的是双向边，防止出现因回到自己的父亲而死循环或者错误转移的情况 
        dfs(y, x); // 递归求解 
        siz[x] += siz[y]; // 更新当前点子树的大小 
        for(register int j = min(m, siz[x]); j >= 0; j--) // 最大取值为最多取的黑点的数量的子树大小的更小值， 再大的状态意义不合法 
        {
            for(register int k = 0; k <= min(j, siz[y]); k++) // 同上，由于是要更新的状态的黑点数量为 j，所以在这个枚举中的上限要和 j 取更小值 
            {
                if(f[x][j - k] == -1) continue; // 特判掉不合法的情况 
                long long val = 1ll * e[i].w * k * (m - k) + 1ll * e[i].w * (siz[y] - k) * (n - m - siz[y] + k); // 这是新产生的贡献，由于很长的缘故，单独写出来 
                f[x][j] = max(f[x][j], f[x][j - k] + f[y][k] + val); // 看是否能够更新答案 
            }
        }
    }
}

signed main()
{
    memset(head, -1, sizeof(head)); 
    memset(f, -1, sizeof(f)); // 答案数组的预处理 
    n = read(); m = read();
    for(register int i = 1; i < n; i++) 
    {
        fr = read(); to = read(); haj = read();
        add(fr, to, haj); // 加双向边 
        add(to, fr, haj);
    }
    dfs(1, 0); // 递归求解 
    cout << f[1][m] << '\n';
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[60],b[60];
int main()
{
    int x,y,z;
    int i;

    cin>>x>>y>>z;
    for(i=1;i<=x;i++)
    {
        a[i]=1;//a[i]��i���µĳɳ�
        b[i]=0;//b[i]��i���µ���
    }
    for(i=x+1;i<=z+1;i++)
    {
        b[i]=a[i-x]*y;//��i-x�µĳɳ���x���º����y����
        a[i]=a[i-1]+b[i-2];//��i���µĳɳ���ڵ�i-1���µĳɳ������ϵ�i-2���µ���
    }

    cout<<a[z+1]<<endl;
    return 0;
}

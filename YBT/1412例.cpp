#include<iostream>
using namespace std;
bool judge(int x);

int main()
{
    int a=0,b=0;
    int i;

    for(i=1; i<=1000; i++) //ö��1-1000����
        if(judge(i))//��i��A����
            a++;
        else//��i��B����
            b++;
    cout<<a<<" "<<b<<endl;
    return 0;
}

bool judge(int x)
{
    int a=0,b=0;
    while(x>0)//��һ������Ϊ��������,���ж���A��������B����
    {
        if(x%2)
            a++;//aͳ��1�ĸ���
        else
            b++;//bͳ��0�ĸ���
        x/=2;
    }

    return a>b;//
}

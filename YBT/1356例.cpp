#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define PI acos(-1.0)
#define E 1e-9
#define INF 0x3f3f3f3f
#define LL long long
const int MOD=1000000007;
const int N=10000+5;
const int dx[]= {-1,1,0,0};
const int dy[]= {0,0,-1,1};
using namespace std;

int n,m;
stack<int> s1;//������ջ
stack<char> s2;//�����ջ

int lev(char x){//��������ȼ�
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

void calculate(stack<int> &s1,stack<char> &s2){//����ջ��Ԫ�ز�����
    /*ȡ���󵯳�ջ*/
    int y=s1.top();
        s1.pop();
    int x=s1.top();
        s1.pop();
    char z=s2.top();
        s2.pop();

    /*�������������,��ѹ��ջ*/
    if(z=='+')
        s1.push(x+y);
    if(z=='-')
        s1.push(x-y);
    if(z=='*')
        s1.push(x*y);
    if(z=='/')
        s1.push(x/y);
    if(z=='^')
        s1.push(pow(x,y));
}

int c(int x){
    return x!=0;
}
char str[1000000];
int sum[1000000];

int main(){

    scanf("%s",str+1);
    n=strlen(str+1);

    for(int i=1;i<=n;i++){//���ƥ��
        sum[i]+=sum[i-1];
        if(str[i]=='(')
            sum[i]++;
        if(str[i]==')')
            sum[i]--;
    }

    bool out=false;
    for(int i=2;i<=n;i++)
        if( c(lev(str[i])) && c(lev(str[i-1])) ){
            out=1;
            break;
        }

    if( ( n==1 && c(lev(str[1])) )||sum[n]||out ){//���ʽ���Ϸ�
        cout<<"NO"<<endl;
        return 0;
    }

    stack<int> s1;
    stack<char> s2;
    int temp=0;
    bool flag=false;
    for(int i=1;i<=n;i++){
        if('0'<=str[i]&&str[i]<='9'){//�жϵ�ǰ�ַ��Ƿ�Ϊ����
            temp=(temp<<3)+(temp<<1)+str[i]-'0';
            flag=true;
        }else{
            if(flag){
                s1.push(temp);
                temp=0;
                flag=false;
            }
            if(str[i]=='('){
                s2.push(str[i]);
                continue;
            }
            if(str[i]==')'){
                while(s2.top()!='(')
                    calculate(s1,s2);
                s2.pop();
                continue;
            }
            while(!s2.empty()&&lev(s2.top())>=lev(str[i]))//���ȼ��ж�
                calculate(s1,s2);
            s2.push(str[i]);//�������ջ
        }
    }
    if(flag){
        s1.push(temp);
        temp=0;
        flag=false;
    }
    while(!s2.empty())
        calculate(s1,s2);
    cout<<s1.top()<<endl;
    return 0;
}

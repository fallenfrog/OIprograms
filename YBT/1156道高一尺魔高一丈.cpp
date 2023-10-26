#include<iostream>;
#include<cmath>;
using namespace std;
double calculate(double x);

int main()
{
    double a,pi;
    a = 1/sqrt(3);//���㹫ʽ�Ĳ���
    pi = 6*(calculate(a));//���ú�������
    printf("%.10lf\n",pi);//����ʮλС�����
    return 0;
}
double calculate(double x)
{
    double sum = 0,temp = x;
    int i = 1;

    while(fabs(temp/i)>=1e-6)//���һ�����ֵ����10^(-6)ʱ����ѭ��
    {
        sum += temp/i;//�ۼӸ���
        temp = -1*x*x*temp;//����һ��
        i += 2;//ϵ��&#43;2
    }
    return sum;
}

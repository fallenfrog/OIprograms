#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
float BBlood,BBloodb,Blood,Round;
int attack,Blod,BBlod,I,k,X,W=1;
void SlowDisplay(int x,char *p)
{
    while(1)
    {
        if(*p!=0) printf("%c",*p++);
        else break;Sleep(x);
    }
}
void Die()
{
    system("cls"); 
    SlowDisplay(50,"\nWarning!\nSYSTEM ERROR!!\nThe system is about to collapse!!!");
    Sleep(1000);X=1;
    cout << "ɵ��̥��";
}
bool Pan()
{
    if(kbhit())
    {
        char a=_getch();
        if(a=='6') k=1;
        else if(a!=' ') X=1;
    }
}
bool Er(int a)
{
    k=0;
    for(int i=1;i<=1000;i++)
    {
        I++;
        if(k==1||X==1) break;
        cout<<"C:/Users/test>ϵͳ�ļ�";
        int R=rand()%5+5;int p;
        for(int j=1;j<=R;j++) p=rand()%26+'a',printf("%c",p); cout<<'.';
        for(int j=1;j<=3;j++) p=rand()%26+'a',printf("%c",p);
        int RR=rand()%5,E=rand()%200+300;
        if(RR==0) cout<<"����."<<endl;
        if(RR==1) cout<<"����,�������������."<<endl;
        if(RR==2) cout<<"����,���ڳ����޸�."<<endl;
        if(RR==3) cout<<"����,����ͣ��."<<endl;
        if(RR==4) cout<<"����,Ԥ�ƻ�Ҫ�ȴ�"<<E<<"00��."<<endl;
        if(I<20) Sleep(100);
    }
    if(a==1) for(int i=0;i<=300;i++) {cout<<"̥��6��6!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(a==2) for(int i=0;i<=200;i++) {cout<<"��˵ʲô!!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(a==3) for(int i=0;i<=100;i++) {cout<<"��˵һ��!!!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(k==0) Die();
    return 0;
}
bool KO()
{
    system("cls");
    SlowDisplay(50,"C:/Users/test>ϵͳ�ļ�windows.h����.\n");
    SlowDisplay(30,"C:/Users/test>ϵͳ�ļ�locale.ct����,�������������.\n");
    SlowDisplay(10,"C:/Users/test>ϵͳ�ļ�Google Chrome����,���ڳ����޸�.\n");
    SlowDisplay(5,"C:/Users/test>ϵͳ�ļ�htmlview.tcl����,Ԥ�ƻ�Ҫ�ȴ�51400��.\n");
    SlowDisplay(2,"C:/Users/test>ϵͳ�ļ�mfile.xbm����,���ڳ����޸�.\n");
    SlowDisplay(1,"C:/Users/test>ϵͳ�ļ�pt_BR.po����,����ʧЧ.\n");
    Er(1);if(X==1) return 0;
    Er(2);if(X==1) return 0;
    Er(3);if(X==1) return 0;W=1;
    return 0;
}
void War()
{
    system("cls");
    cout<<endl<<"-----------��"<<Round<<"�غ�----------"<<endl<<endl;Sleep(1000);
    cout<<"����Ѫ����"<<Blood<<endl<<endl;Sleep(500);
    if(Round<=3) cout<<"̥��Ѫ����"<<BBlood<<endl<<endl;
    else if(Round<=9)printf("̥��Ѫ����%0.9f\n\n",BBlood);
    else if(Round==10)printf("̥��Ѫ����%di\n\n",Blod);
    else printf("̥��Ѫ����%di %d\n\n",Blod,BBlod);Sleep(500);
    A: cout<<"���Ĺ�����50�����ո񹥻���"<<endl<<endl;
    char a=_getch();if(a!=' ') {cout<<"��Ч���롣"<<endl<<endl;goto A;}
    attack=rand()%10+45;Sleep(500);
    if(Round==7) attack=rand()%10+95,cout<<"��������,����...",Sleep(500),cout<<"����������"<<attack<<"���˺���"<<endl<<endl;
    else cout<<"�������ˣ����"<<attack<<"���˺���"<<endl<<endl;Sleep(500);
}
bool Tai()
{
    if(Round<=9) cout<<"̥������ˣ�"<<endl<<endl;Sleep(500);
    if(Round<=6) cout<<"���Ĺ���";
    else if(Round<=9) cout<<"����Ѫ��";
    else if(Round>=10) BBlod-=attack;
    else BBlood-=attack; Sleep(1000);
    int kk=Round;
    switch(kk)
    {
        case 1:
        {
            cout<<"������ˣ���Ϊ";
            int a1=attack/10,a2=attack%10;
            cout<<a1<<'+'<<a2<<"���˺���"<<endl<<endl;
            BBlood-=a1+a2;break;
        }
        case 2:
        {
            cout<<"���෴���ˣ���Ϊ";
            cout<<-1*attack<<"���˺���"<<endl<<endl;
            BBlood+=attack;break;
        }
        case 3:
        {
            cout<<"�������ˣ���Ϊ";
            float a=sqrt(attack);
            printf("%0.9f���˺���\n\n",a);
            BBlood-=a;break;
        }
        case 4:
        {
            cout<<"��0.9���ˣ���Ϊ";
            float a=pow(0.9,attack);
            printf("%0.9f���˺���\n\n",a);
            BBlood-=a;break;
        }
        case 5:
        {
            cout<<"����Ȼ�����ˣ���Ϊ";
            float a=log(attack);
            printf("%0.9f���˺���\n\n",a);
            BBlood-=a;break;
        }
        case 6:
        {
            cout<<"�������ˣ���Ϊ";
            float a=sin(attack);
            printf("%0.9f���˺���\n\n",a);
            BBlood-=a;break;
        }
        case 7:
        {
            BBlood-=attack;
            cout<<"������ֵ�ˣ���Ϊ��";
            printf("%0.9f\n\n",-BBlood);
            BBlood*=-1;break;
        }
        case 8:
        {
            cout<<"��Բ�ˣ�Ѫ����Ϊ��";
            float a=3.141592653;
            printf("%0.9f",BBlood);Sleep(500);
            SlowDisplay(20,"*3.1415926535��\n\n");
            BBlood*=a;break;
        }
        case 9:
        {
            Blod=BBlood;
            cout<<"�������ˣ���Ϊ��";
            printf("%di\n\n",Blod);
            break;
        }
        case 10:
        {
            cout<<"���Ĺ���������ʼ���ˣ���Ϊ��0x7f7f7f7f��\n\n";
            break;
        }
    }Sleep(500);
    if(Round<=9) cout<<"̥�񹥻��ˣ�"<<endl<<endl;Sleep(500);int attack2=rand()%5+1;
    if(Round<=9) cout<<"����Ѫ��-"<<attack2,Sleep(1000),Blood-=attack2;
    else
    {
        switch(kk)
        {
            case 10:{cout<<"̥������һ��..."<<endl<<endl;Sleep(500);int attack2=rand()%10+95;cout<<"����Ѫ��-"<<attack2;Blood-=attack2;break;}
            case 11:{cout<<"̥���ֿ�����һ��..."<<endl<<endl;Sleep(500);int attack2=rand()%10+195;cout<<"����Ѫ��-"<<attack2;Blood-=attack2;break;}
            case 12:{cout<<"̥��ȥ����һ���,˳�㿴����һ��..."<<endl<<endl;Sleep(500);int attack2=rand()%10+295;cout<<"����Ѫ��-"<<attack2;Blood-=attack2;break;}
            case 13:{cout<<"̥��������,���ǿ�����һ��..."<<endl<<endl;Sleep(500);int attack2=Blood-1;cout<<"����Ѫ��-"<<attack2;Blood-=attack2;break;}
            case 14:
            {
                cout<<"̥�񿪿�˵���ˣ�����"<<endl<<endl;
                Sleep(500);
                SlowDisplay(200,"��.......������֪�����డ......\n\n");
                SlowDisplay(200,"�㻹��̫���˰�......\n\n");
                SlowDisplay(200,"����.......\n\n");
                SlowDisplay(200,"�һ��Ǹ���һ��Ӯ�Ļ����......\n\n");
                SlowDisplay(200,"�ҷ�Ȱ����ַ������ּ�����......\n\n");
                SlowDisplay(200,"�۾�ע����Ļ......\n\n");
                KO();if(W==1) system("cls"),SlowDisplay(200,"лл�佱������ͨ�ذɣ�");
                break;
            }
        }
        Sleep(1000);
    }return 0;
}
int main()
{
    srand((unsigned)time(NULL));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    BBlood=50;Blood=1000;
    SlowDisplay(2,"��ӭ����Σ����Ϸ�����Ŀ���Ǵ��̥��\n\n");
    Sleep(1000);system("cls"); 
    while(1)
    {
        Round++;War();Tai();
        if(Round>=14) break;
    }
    return 0;
}

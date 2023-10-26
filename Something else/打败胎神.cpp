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
    cout << "傻逼胎神";
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
        cout<<"C:/Users/test>系统文件";
        int R=rand()%5+5;int p;
        for(int j=1;j<=R;j++) p=rand()%26+'a',printf("%c",p); cout<<'.';
        for(int j=1;j<=3;j++) p=rand()%26+'a',printf("%c",p);
        int RR=rand()%5,E=rand()%200+300;
        if(RR==0) cout<<"已损坏."<<endl;
        if(RR==1) cout<<"已损坏,正在联机检查结果."<<endl;
        if(RR==2) cout<<"已损坏,正在尝试修复."<<endl;
        if(RR==3) cout<<"已损坏,即将停用."<<endl;
        if(RR==4) cout<<"已损坏,预计还要等待"<<E<<"00秒."<<endl;
        if(I<20) Sleep(100);
    }
    if(a==1) for(int i=0;i<=300;i++) {cout<<"胎神6不6!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(a==2) for(int i=0;i<=200;i++) {cout<<"你说什么!!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(a==3) for(int i=0;i<=100;i++) {cout<<"再说一遍!!!"<<endl;Pan();if(k==1||X==1) break;Sleep(1);}
    if(k==0) Die();
    return 0;
}
bool KO()
{
    system("cls");
    SlowDisplay(50,"C:/Users/test>系统文件windows.h已损坏.\n");
    SlowDisplay(30,"C:/Users/test>系统文件locale.ct已损坏,正在联机检查结果.\n");
    SlowDisplay(10,"C:/Users/test>系统文件Google Chrome已损坏,正在尝试修复.\n");
    SlowDisplay(5,"C:/Users/test>系统文件htmlview.tcl已损坏,预计还要等待51400秒.\n");
    SlowDisplay(2,"C:/Users/test>系统文件mfile.xbm已损坏,正在尝试修复.\n");
    SlowDisplay(1,"C:/Users/test>系统文件pt_BR.po已损坏,即将失效.\n");
    Er(1);if(X==1) return 0;
    Er(2);if(X==1) return 0;
    Er(3);if(X==1) return 0;W=1;
    return 0;
}
void War()
{
    system("cls");
    cout<<endl<<"-----------第"<<Round<<"回合----------"<<endl<<endl;Sleep(1000);
    cout<<"您的血量："<<Blood<<endl<<endl;Sleep(500);
    if(Round<=3) cout<<"胎神血量："<<BBlood<<endl<<endl;
    else if(Round<=9)printf("胎神血量：%0.9f\n\n",BBlood);
    else if(Round==10)printf("胎神血量：%di\n\n",Blod);
    else printf("胎神血量：%di %d\n\n",Blod,BBlod);Sleep(500);
    A: cout<<"您的攻击力50，按空格攻击。"<<endl<<endl;
    char a=_getch();if(a!=' ') {cout<<"无效输入。"<<endl<<endl;goto A;}
    attack=rand()%10+45;Sleep(500);
    if(Round==7) attack=rand()%10+95,cout<<"您攻击了,并且...",Sleep(500),cout<<"暴击！！！"<<attack<<"点伤害！"<<endl<<endl;
    else cout<<"您攻击了！造成"<<attack<<"点伤害！"<<endl<<endl;Sleep(500);
}
bool Tai()
{
    if(Round<=9) cout<<"胎神防御了！"<<endl<<endl;Sleep(500);
    if(Round<=6) cout<<"您的攻击";
    else if(Round<=9) cout<<"他的血量";
    else if(Round>=10) BBlod-=attack;
    else BBlood-=attack; Sleep(1000);
    int kk=Round;
    switch(kk)
    {
        case 1:
        {
            cout<<"被拆分了！变为";
            int a1=attack/10,a2=attack%10;
            cout<<a1<<'+'<<a2<<"点伤害！"<<endl<<endl;
            BBlood-=a1+a2;break;
        }
        case 2:
        {
            cout<<"被相反数了！变为";
            cout<<-1*attack<<"点伤害！"<<endl<<endl;
            BBlood+=attack;break;
        }
        case 3:
        {
            cout<<"被开方了！变为";
            float a=sqrt(attack);
            printf("%0.9f点伤害！\n\n",a);
            BBlood-=a;break;
        }
        case 4:
        {
            cout<<"被0.9幂了！变为";
            float a=pow(0.9,attack);
            printf("%0.9f点伤害！\n\n",a);
            BBlood-=a;break;
        }
        case 5:
        {
            cout<<"被自然对数了！变为";
            float a=log(attack);
            printf("%0.9f点伤害！\n\n",a);
            BBlood-=a;break;
        }
        case 6:
        {
            cout<<"被正弦了！变为";
            float a=sin(attack);
            printf("%0.9f点伤害！\n\n",a);
            BBlood-=a;break;
        }
        case 7:
        {
            BBlood-=attack;
            cout<<"被绝对值了！变为了";
            printf("%0.9f\n\n",-BBlood);
            BBlood*=-1;break;
        }
        case 8:
        {
            cout<<"变圆了！血量变为了";
            float a=3.141592653;
            printf("%0.9f",BBlood);Sleep(500);
            SlowDisplay(20,"*3.1415926535！\n\n");
            BBlood*=a;break;
        }
        case 9:
        {
            Blod=BBlood;
            cout<<"被虚数了！变为了";
            printf("%di\n\n",Blod);
            break;
        }
        case 10:
        {
            cout<<"他的攻击力被初始化了！变为了0x7f7f7f7f！\n\n";
            break;
        }
    }Sleep(500);
    if(Round<=9) cout<<"胎神攻击了！"<<endl<<endl;Sleep(500);int attack2=rand()%5+1;
    if(Round<=9) cout<<"您的血量-"<<attack2,Sleep(1000),Blood-=attack2;
    else
    {
        switch(kk)
        {
            case 10:{cout<<"胎神看了你一眼..."<<endl<<endl;Sleep(500);int attack2=rand()%10+95;cout<<"您的血量-"<<attack2;Blood-=attack2;break;}
            case 11:{cout<<"胎神又看了你一眼..."<<endl<<endl;Sleep(500);int attack2=rand()%10+195;cout<<"您的血量-"<<attack2;Blood-=attack2;break;}
            case 12:{cout<<"胎神去颓了一会儿,顺便看了你一眼..."<<endl<<endl;Sleep(500);int attack2=rand()%10+295;cout<<"您的血量-"<<attack2;Blood-=attack2;break;}
            case 13:{cout<<"胎神无聊了,还是看了你一眼..."<<endl<<endl;Sleep(500);int attack2=Blood-1;cout<<"您的血量-"<<attack2;Blood-=attack2;break;}
            case 14:
            {
                cout<<"胎神开口说话了！！！"<<endl<<endl;
                Sleep(500);
                SlowDisplay(200,"啊.......愚昧无知的人类啊......\n\n");
                SlowDisplay(200,"你还是太弱了啊......\n\n");
                SlowDisplay(200,"算了.......\n\n");
                SlowDisplay(200,"我还是给你一次赢的机会吧......\n\n");
                SlowDisplay(200,"我奉劝你把手放在数字键盘上......\n\n");
                SlowDisplay(200,"眼睛注意屏幕......\n\n");
                KO();if(W==1) system("cls"),SlowDisplay(200,"谢谢夸奖！让你通关吧！");
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
    SlowDisplay(2,"欢迎来到危险游戏！你的目标是打败胎神！\n\n");
    Sleep(1000);system("cls"); 
    while(1)
    {
        Round++;War();Tai();
        if(Round>=14) break;
    }
    return 0;
}

//转自：https://www.luogu.com.cn/blog/I-am-your-dad/xiao-you-hu-7-shuai-dian-nao-you-hu
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;
string s,m;
int i,j,BUGs,k,x,sj,bf,bl,sy,c,f;
bool t;
int main(){
    system("mode con cols=50 lines=20");
    cout<<"游戏版本：1.3.1 正式版本\n";
    cout<<"温馨提示：玩此游戏你可能崩溃\n";
    cout<<"就问你做好砸电脑的准备了吗?\n";
    cout<<"任意键继续...";
    getch();system("cls");
    cout<<"目标是:A了这道题\n";
    cout<<"祝你们成功(滑稽)\n";
    cout<<"你确认要进入吗?\n";
    cout<<"任意键继续...";
    getch();system("cls");
    cout<<"请选择模式...\n";
    cout<<"1=菜鸡,2=大佬,3=巨佬,4=贼刺激\n";
    cin>>m;system("cls");
    while(m!="1"&&m!="2"&&m!="3"&&m!="4"){
        cout<<"请重新选择模式...\n";
        cout<<"1=菜鸡,2=大佬,3=巨佬,4=贼刺激\n";
        cin>>m;system("cls");
    }
    if(m=="1") c=250,f=0;
    if(m=="2") c=220,f=10;
    if(m=="3") c=200,f=20;
    if(m=="4") c=180,f=30;
    for(i=0;i<=100;i++){
        cout<<"进度:"<<i<<"% 时间:"<<++sj<<" 分数："<<++f<<" 请在"<<c<<"秒内完成"<<endl;
        for(j=1;j<=i/2;j++)
            cout<<"<";
        Sleep(100);
        system("cls");
        srand(time(NULL));
        k=(rand()%233+i*i)%20;
        if(k==0){
            cout<<"发现一个BUG！\n";
            t=1;
            while(t){
                cout<<"要不要修？\n";
                cout<<"1=修,2=不修\n";
                s="";cin>>s;
                while(s!="1"&&s!="2"){
                    cout<<"修不修？\n";
                    cout<<"1=修,2=不修\n";
                    s="";cin>>s;
                }
                if(s=="1"){
                    f++;
                    cout<<"5秒之后...\n";
                    sj+=5;
                    if(sj>c){
                        cout<<"时间到了！\n";
                        return 0;
                    }
                    srand(time(NULL));
                    x=rand()%5;
                    if(x==0){
                        cout<<"BUG被修好了！\n";
                        t=0;f+=10;
                    }
                    else cout<<"BUG没被修好！\n"; 
                }
                else{
                    t=0;
                    BUGs++;
                }
            }
            Sleep(1000);
            system("cls");
        }
        if(k==1){
            cout<<"你的损友向你伸出了手...\n";
            t=1;
            while(t){
                cout<<"要不要赶走他?\n";
                cout<<"1=赶,2=不赶\n";
                s="";cin>>s;
                while(s!="1"&&s!="2"){
                    cout<<"要不要赶走他?\n";
                    cout<<"1=赶,2=不赶\n";
                    s="";cin>>s;
                }
                if(s=="1"){
                    f++;
                    cout<<"3秒之后...\n";
                    sj+=3;
                    if(sj>c){
                        cout<<"时间到了！\n";
                        return 0;
                    }
                    srand(time(NULL));
                    x=rand()%5;
                    if(x==0){
                        cout<<"损友被赶跑啦！\n";
                        t=0;f+=10;
                    }
                    else cout<<"损友又回来了！\n"; 
                }
                else{
                    t=0;
                    srand(time(NULL));
                    sy=rand()%3;
                    if(sy==0){
                        cout<<"损友使用三点杀！关机了...\n";
                        i=0;BUGs=0;f+=20;
                    }
                    else cout<<"损友没按到键盘...\n";
                }
            }
            Sleep(1000);
            system("cls");
        }
        srand(time(NULL));
        bf=rand()%12+1;
        if(bf<=BUGs){
            BUGs--;
            cout<<" $^%&%*%&$ % $#$ @ $#%$ &^%*^& $#$ !%$#^%&%^#%@%(抽搐)\n";
            cout<<"BUG发作了！\n";
            srand(time(NULL));
            bl=rand()%2;
            if(bl==0){
                cout<<"进度归0！\n";
                i=0;f+=20;
            }
            else{
                cout<<"进度变成了原来的一半！\n";
                i/=2;f+=10;
            }
            Sleep(3000);
            system("cls");
        }
        if(sj>c){
            cout<<"时间到了！\n";
            return 0;
        }
    }
    cout<<"成功！\n";
    cout<<"你的得分："<<f; 
    return 0;
}

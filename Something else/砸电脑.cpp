//ת�ԣ�https://www.luogu.com.cn/blog/I-am-your-dad/xiao-you-hu-7-shuai-dian-nao-you-hu
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
    cout<<"��Ϸ�汾��1.3.1 ��ʽ�汾\n";
    cout<<"��ܰ��ʾ�������Ϸ����ܱ���\n";
    cout<<"�����������ҵ��Ե�׼������?\n";
    cout<<"���������...";
    getch();system("cls");
    cout<<"Ŀ����:A�������\n";
    cout<<"ף���ǳɹ�(����)\n";
    cout<<"��ȷ��Ҫ������?\n";
    cout<<"���������...";
    getch();system("cls");
    cout<<"��ѡ��ģʽ...\n";
    cout<<"1=�˼�,2=����,3=����,4=���̼�\n";
    cin>>m;system("cls");
    while(m!="1"&&m!="2"&&m!="3"&&m!="4"){
        cout<<"������ѡ��ģʽ...\n";
        cout<<"1=�˼�,2=����,3=����,4=���̼�\n";
        cin>>m;system("cls");
    }
    if(m=="1") c=250,f=0;
    if(m=="2") c=220,f=10;
    if(m=="3") c=200,f=20;
    if(m=="4") c=180,f=30;
    for(i=0;i<=100;i++){
        cout<<"����:"<<i<<"% ʱ��:"<<++sj<<" ������"<<++f<<" ����"<<c<<"�������"<<endl;
        for(j=1;j<=i/2;j++)
            cout<<"<";
        Sleep(100);
        system("cls");
        srand(time(NULL));
        k=(rand()%233+i*i)%20;
        if(k==0){
            cout<<"����һ��BUG��\n";
            t=1;
            while(t){
                cout<<"Ҫ��Ҫ�ޣ�\n";
                cout<<"1=��,2=����\n";
                s="";cin>>s;
                while(s!="1"&&s!="2"){
                    cout<<"�޲��ޣ�\n";
                    cout<<"1=��,2=����\n";
                    s="";cin>>s;
                }
                if(s=="1"){
                    f++;
                    cout<<"5��֮��...\n";
                    sj+=5;
                    if(sj>c){
                        cout<<"ʱ�䵽�ˣ�\n";
                        return 0;
                    }
                    srand(time(NULL));
                    x=rand()%5;
                    if(x==0){
                        cout<<"BUG���޺��ˣ�\n";
                        t=0;f+=10;
                    }
                    else cout<<"BUGû���޺ã�\n"; 
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
            cout<<"������������������...\n";
            t=1;
            while(t){
                cout<<"Ҫ��Ҫ������?\n";
                cout<<"1=��,2=����\n";
                s="";cin>>s;
                while(s!="1"&&s!="2"){
                    cout<<"Ҫ��Ҫ������?\n";
                    cout<<"1=��,2=����\n";
                    s="";cin>>s;
                }
                if(s=="1"){
                    f++;
                    cout<<"3��֮��...\n";
                    sj+=3;
                    if(sj>c){
                        cout<<"ʱ�䵽�ˣ�\n";
                        return 0;
                    }
                    srand(time(NULL));
                    x=rand()%5;
                    if(x==0){
                        cout<<"���ѱ���������\n";
                        t=0;f+=10;
                    }
                    else cout<<"�����ֻ����ˣ�\n"; 
                }
                else{
                    t=0;
                    srand(time(NULL));
                    sy=rand()%3;
                    if(sy==0){
                        cout<<"����ʹ������ɱ���ػ���...\n";
                        i=0;BUGs=0;f+=20;
                    }
                    else cout<<"����û��������...\n";
                }
            }
            Sleep(1000);
            system("cls");
        }
        srand(time(NULL));
        bf=rand()%12+1;
        if(bf<=BUGs){
            BUGs--;
            cout<<" $^%&%*%&$ % $#$ @ $#%$ &^%*^& $#$ !%$#^%&%^#%@%(�鴤)\n";
            cout<<"BUG�����ˣ�\n";
            srand(time(NULL));
            bl=rand()%2;
            if(bl==0){
                cout<<"���ȹ�0��\n";
                i=0;f+=20;
            }
            else{
                cout<<"���ȱ����ԭ����һ�룡\n";
                i/=2;f+=10;
            }
            Sleep(3000);
            system("cls");
        }
        if(sj>c){
            cout<<"ʱ�䵽�ˣ�\n";
            return 0;
        }
    }
    cout<<"�ɹ���\n";
    cout<<"��ĵ÷֣�"<<f; 
    return 0;
}

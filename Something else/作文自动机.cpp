#include<bits/stdc++.h>
using namespace std; 
int j;
string nouns[200]={"С��","̫��","����","����","�ݵ�","�ܶ�����"};
string verbs[200]={"����","�ɳ�","����","��˯","����","ͻ��"};
string adj[200]={"���յ�","δ����","������","ʹ���","������","���и��������"};
string adv[200]={"Ѹ�ٵ�","���ֵ�","��ŭ��","���ŵ�","���ŵ�","�¸ҵ�"};
string like[200]={"��ѩ�а����ĺ�÷","���峿�����̫��","��й������Ƥ��","��һ����ҫ�Ĺ�"};
string connect[200]={"��","��","��"};
string ques[200]={"Ϊʲô","�����","��ʱ����"};
string gt[200]={"��ô","��һ��","����"};
string gtback[200]={"��","��","ѽ"};
string obq[200]={"�ѵ�","����","��ô"};
string obend[200]={"��","��"};
string conj1[200]={"�������","��Ȼ���","���������Ļ�","������","�ܵ���˵","����","һ�������������ŵ���ʵ��"}; 
string famous[11]={"����������˵��:�ɹ�����1%����к�99%��Ŭ��.","��ɽ��ɽ������ˮ��ɽ,","ʧ���ǳɹ�֮ĸ,",
"���˼�ڡ��ʱ��ۡ����ᵽ:��10%������,�ʱ��ͻ��Ծ����,.....��100%������,�ʱ��͸Ҽ�̤�˼䷨��,��300%������,�ʱ��᲻�˱������ķ���.",
"�����˵,�˵���ְ������̽������.",
"�׷������ռ����ᵽ,�˵����������޵ģ����ǣ�Ϊ������������޵ģ���Ҫ�����޵�������Ͷ�뵽���޵�Ϊ�������֮��ȥ��" ,
"�����Ϊ,�˵��ǻ�����������Կ�ף�һ�ѿ������֣�һ�ѿ�����ĸ��һ�ѿ���������֪ʶ��˼�롢����������С�",
"����˹̹˵,��ֻ����������ᣬ�����ҳ��Ƕ��ݶ��з��յ����������塣" ,
"³Ѹ����, ϣ���Ǹ����ڴ��ڵģ��д��ڣ�����ϣ������ϣ�������ǹ�����" ,
"ɯʿ����˵, ����ʱ����ˣ�ʱ��Ҳ��������",
"���������˵��,�ƽ�ʱ����������ǰ���������Ǳ���" };
bool said[4];
int checkfame(int x){
    if(said[x])return x;
    else{
        for(int i=1;i<=11;i++){
            if(said[x])return x;
        }
    }
    return -1;
} 
int rand_number(int x){
    srand(time(NULL)+x*x);
    return rand()+x*x;
}
void say_sentence(int y){
    int GCCsb=rand_number(2212+y)%7;
    if(GCCsb%2==0)cout<<conj1[GCCsb]<<","; 
    int n=rand_number(233+y)%6;
    int v=rand_number(333+y)%6;
    int aj=rand_number(444+y)%6;
    int av=rand_number(555+y)%6;
    int alike=rand_number(666+y)%12;
    int c=rand_number(777+y)%3;
    cout<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<verbs[v]<<connect[c]<<".";
}

void question(int y){
    int n=rand_number(233+y)%6;
    int v=rand_number(333+y)%6;
    int aj=rand_number(444+y)%6;
    int av=rand_number(555+y)%6;
    int alike=rand_number(666+y)%15;
    int c=rand_number(777+y)%3;
    int qq=rand_number(888+y)%3;
    int num=rand_number(999+y)%2;
    int ob1=rand_number(1111+y)%3;
    int ob2=rand_number(2222+y)%2;
    if(num)cout<<ques[qq]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<verbs[v]<<connect[c]<<"?";
    else cout<<obq[ob1]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<"��"<<verbs[v]<<obend[ob2]<<"?";
}
void gts(int y){
    int n=rand_number(233+y)%5;
    int v=rand_number(333+y)%5;
    int aj=rand_number(444+y)%5;
    int av=rand_number(555+y)%5;
    int gg=rand_number(8888+y)%3;
    int ggg=rand_number(9999+y)%3;
    cout<<adj[aj]<<nouns[n]<<gt[gg]<<adv[av]<<verbs[v]<<gtback[ggg]<<"!";
}
void paragraph(int y){
    cout<<"    ";
    y=rand_number(j+1)%12+18;
    for(int i=1;i<=y;i++){
        int u=rand_number(i+11+j)%3;
        if(u)say_sentence(i+56+y);
        else{
            int uu=rand_number(i+22+y)%100;
            if(uu<=20)gts(i+888+y);
            else if(uu<=52) question(i+8848+y*y);
            else cout<<famous[rand_number(i+4+y)%11];
        }
    }
    cout<<endl;
}
int main(){
    freopen("����.txt","w",stdout);
    int sq=rand_number(6666)%3;
    int paras=rand_number(3333)%300+500;
    for(j=1;j<=paras;j++){
        paragraph(j+1);
    }
}

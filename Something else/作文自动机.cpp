#include<bits/stdc++.h>
using namespace std; 
int j;
string nouns[200]={"小明","太阳","花儿","世界","草地","奋斗者们"};
string verbs[200]={"绽放","成长","毁灭","沉睡","哭泣","突破"};
string adj[200]={"昔日的","未来的","美丽的","痛苦的","新生的","富有革命精神的"};
string adv[200]={"迅速地","快乐地","愤怒地","慌张地","自信地","勇敢地"};
string like[200]={"如雪中傲立的寒梅","如清晨升起的太阳","像泄了气的皮球","像一道闪耀的光"};
string connect[200]={"着","了","过"};
string ques[200]={"为什么","如何让","何时能有"};
string gt[200]={"多么","好一个","真是"};
string gtback[200]={"啊","哇","呀"};
string obq[200]={"难道","怎能","怎么"};
string obend[200]={"吗","呢"};
string conj1[200]={"无论如何","既然如此","根据上述的话","如此这般","总的来说","并且","一个令人难以置信的事实是"}; 
string famous[11]={"爱迪生曾经说过:成功来自1%的灵感和99%的努力.","金山银山不如绿水青山,","失败是成功之母,",
"马克思在《资本论》中提到:有10%的利润,资本就会活跃起来,.....有100%的利润,资本就敢践踏人间法律,有300%的利润,资本会不顾被绞死的风险.",
"哥白尼说,人的天职在勇于探索真理.",
"雷锋曾在日记中提到,人的生命是有限的，可是，为人民服务是无限的，我要把有限的生命，投入到无限的为人民服务之中去。" ,
"雨果认为,人的智慧掌握着三把钥匙，一把开启数字，一把开启字母，一把开启音符。知识、思想、幻想就在其中。",
"爱因斯坦说,人只有献身于社会，才能找出那短暂而有风险的生命的意义。" ,
"鲁迅讲到, 希望是附丽于存在的，有存在，便有希望，有希望，便是光明。" ,
"莎士比亚说, 抛弃时间的人，时间也抛弃他。",
"马克吐温曾说过,黄金时代在我们面前而不在我们背后。" };
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
    else cout<<obq[ob1]<<adj[aj]<<nouns[n]<<adv[av]<<like[alike]<<"不"<<verbs[v]<<obend[ob2]<<"?";
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
    freopen("文章.txt","w",stdout);
    int sq=rand_number(6666)%3;
    int paras=rand_number(3333)%300+500;
    for(j=1;j<=paras;j++){
        paragraph(j+1);
    }
}

#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
int mzhg,zd,swhm,qxs,swx,sn,mp,tongguan,sw1,zd1,sn1,mz1,mp1,zbbj,ccg,mzzd,mz,tongguan1,sw,x,s,cdd,jg,qiang,gun,by,vv,gjj[100],hjj[100],zjj[100];
void Read()
{
    ifstream in("丧尸危机存档.in");
    in>>mzhg>>zd>>swhm>>qxs>>swx>>sn>>mp>>tongguan>>sw1>>zd1>>sn1>>mz1>>mp1>>zbbj>>ccg>>mzzd>>mz>>tongguan1>>sw>>x>>s>>cdd>>jg>>qiang>>gun>>by>>vv;
    for(int i=0;i<=99;i++) in>>gjj[i];
    for(int i=0;i<=99;i++) in>>hjj[i];
    for(int i=0;i<=99;i++) in>>zjj[i];
    in.close();
}
void Save()
{
    ofstream out("丧尸危机存档.in");
    out<<mzhg<<' '<<zd<<' '<<swhm<<' '<<qxs <<' '<<swx<<' '<<sn<<' '<<mp<<' '<<tongguan<<' '<<sw1<<' '<<zd1<<' '<<sn1<<' '<<mz1<<' '<<mp1<<' '<<zbbj<<' '<<ccg<<' '<<mzzd<<' '<<mz<<' '<<tongguan1<<' '<<sw<<' '<<x<<' '<<s<<' '<<cdd<<' '<<jg<<' '<<qiang<<' '<<gun<<' '<<by<<' '<<vv<<'\n';
    for(int i=0;i<=99;i++) out<<' '<<gjj[i];out<<'\n';
    for(int i=0;i<=99;i++) out<<' '<<hjj[i];out<<'\n';
    for(int i=0;i<=99;i++) out<<' '<<zjj[i];out<<'\n';
    out.close();
}
void Slowsay(string a) {int l=a.size();for(int i=0;i<l;i++){cout<<a[i];if(vv==0) Sleep(20);}printf("\n");if(vv==1) Sleep(100);}
int read()
{
    char ch=_getch();
    while(ch>'9'||ch<'0') ch=_getch();
    return ch-48;
}
void qp()
{
    system("cls");if(swx==2) Slowsay("王，"),zd=99999,sw=99999;
    Slowsay("当前你的状态是\n");
    printf("子弹 %d，食物 %d\n",zd,sw);
}
int esl()
{
    system("cls");
    char ch;
    Slowsay("你，饿死了。\n");
    if(vv==0) ch=_getch();
    hjj[1]=1;
    Slowsay("Bad End  1\n");
    ch=_getch();
    s++;
    return 0;
}
int mzd()
{
    hjj[2]=1;
    system("cls");
    char ch;
    Slowsay("你，被丧尸咬死了。\n");
    if(vv==0) ch=_getch();
    Slowsay("Bad End   2\n");
    ch=_getch();
    s++;
    return 0;
}
int hd1()
{
    system("cls");
    Slowsay("在某一天，你家门口响起了敲门声，你打开门，外面的发现让你欣喜若狂\n");
    Slowsay("政府的救援部队已经消灭了这个城市的丧尸，\n他们在这个城市的各个角落搜索着可能存在的幸存者.\n");
    Slowsay("Happy End-----苟到最后\n");Sleep(1000);gjj[1]=1;
    return 0;
}
int hd2()
{
    system("cls");
    int sw;
    char ch;
    Slowsay("在与妹子相处的这些时间里，你与她相爱了\n");
    Slowsay("你们的生活是那样的幸福\n");
    Slowsay("直到有一天......\n");
    Slowsay("基地首领希望你去执行一个任务，你选择\n");
    Slowsay("1.独自一人前往\n");
    Slowsay("2.和妹子一起去\n");
    while(true)
    {
        int x;
        x=read();
        if(x<1||x>2)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        if(x==1)
        {
            Slowsay("当你完成任务回来的时候，发现——\n");
            Slowsay("基地被丧尸攻破了\n");
            Slowsay("这个基地的所有人都被丧尸杀了，一个人都没跑出来\n");
            hjj[4]=1;
            Slowsay("Bad End    4");
            s++;
        }
        if(x==2)
        {
            Slowsay("当你和妹子完成任务回来时，\n");
            Slowsay("基地已经变成一片废墟了\n");
            Slowsay("你和妹子没有办法，只能到处流浪\n");
            Slowsay("不过，两个人总比一个人要好\n");
            gjj[2]=1;
            Slowsay("Happy End------神仙眷侣"); 
        }
        break;
    }    Sleep(1000); 
    return 0;
}
int hd3()
{
    system("cls");
    char ch;
    Slowsay("你就这样平静的生活在这个基地里\n");
    Slowsay("直到某一天，大量的丧尸进攻了这里\n");
    if(zd>9)
    {
        Slowsay("每个人都在尽自己的努力去守卫基地\n");
        Slowsay("每个人都做到了自己能做到的\n");
        Slowsay("最后，奇迹出现了\n");
        Slowsay("大家成功守住了基地\n");
        Slowsay("而你，也因为在守卫过程中立下大功成为了这个基地的英雄\n");
        Slowsay("顺便说一句，到死了你也没女朋友\n");
        gjj[3]=1;
        Slowsay("Happy End-----英雄不朽");
        return 0;
    }
    Slowsay("丧尸的数量实在太多了，\n");
    Slowsay("尽管基地的大家都在尽全力防守\n");
    Slowsay("可基地还是被攻破了\n");
    Slowsay("而你，也死在了这里\n");
    s++;
    hjj[5]=1;
    Slowsay("Bad End     5"); Sleep(1000); 
}
int hd4()
{
    system("cls");
    Slowsay("在于少年相处的这些时间里");
    Slowsay("你尽力地保护着他");
    Slowsay("而他也常常给你带来惊喜");
    Slowsay("慢慢的，你开始认清你自己");
    Slowsay("你是个gay");
    Slowsay("于是，你就和少年性福快乐的生活在了一起");
    Slowsay("Happy End-----认清自己");
    gjj[4]=1;  Sleep(1000); 
}
int td()
{
    system("cls");
    char ch;
    Slowsay("那箱饼干与你的枪一起发出了强光\n");
    Slowsay("紧接着，他们融为了一体\n");
    Slowsay("当光芒散去时，整个世界都发生了变化\n");
    Slowsay("所有的丧尸都变回了人类\n");
    Slowsay("伟大的勇士！丧尸危机终于解除了！！接下来，是普天同庆的大狂欢！！！\n");
    Slowsay("True End-----拯救世界\n");Sleep(1000); 
    Slowsay("???????????????????????????????????");
    Slowsay("......这是怎么回事......");
    Slowsay("......为什么......");
    Slowsay("......不是普通的......");
    Slowsay("......从何而来......");Sleep(1000); 
    Slowsay("。 。 。 。 。 。是谁。 。 。 。 。 。");
    Slowsay("你陷入沉思。");
    if(zjj[1]!=1)
    {
        Slowsay("获得线索-----奇特的枪与饼干");
    }
    zjj[1]=1; Sleep(1000); 
}
int td2()
{
    system("cls");
    char ch;
    Slowsay("你的变异已经开始了");
    Slowsay("你开始疯狂的进食，直到把自己的胃撑破");
    Slowsay("然后，就眼前一黑失去意识");
    Slowsay("再次醒来时，你已经是一个丧尸了");
    Slowsay("奇怪的是，你还保留着自己的意识");
    Slowsay("你感觉到自己的力气变得更大，速度变得更快");
    Slowsay("或许变成丧尸也不错————你这样想着");
    Slowsay("True End-----认清！·本我"); 
    if(zjj[2]!=1)
    {
        Sleep(2000);
        Slowsay("获得线索-----延迟变异！·少年");
    }
    zjj[2]=1; Sleep(1000); 
}
int bd8()
{
    Slowsay("坐在椅子上的是一个15岁左右的少年");
    Slowsay("正在你因为他的年龄而惊讶时");
    Slowsay("少年却站了起来，看向了你身后的妹子");
    Slowsay("“差不多了吧”，妹子这样说道");
    Slowsay("“可以了”，这是少年的回答");
    Slowsay("然后，你就感到脖子一阵剧痛");Sleep(1000);
    Slowsay("在你失去意识前，妹子一直没有松口。");
    s++;
    Slowsay("Bad End     8");
    if(hjj[8]==0)
    {
        Sleep(2000);
        Slowsay("获得线索-----早已变异！·妹子");
    }
    hjj[8]=1;  Sleep(1000); 
}
int td3()
{
    system("cls");
    Slowsay("你和妹子冲出了丧尸的围杀，");
    Slowsay("可是当你们来到那个幸存者基地时");
    Slowsay("却发现那个基地有一些不对");
    Slowsay("所有人都死气沉沉的");
    Slowsay("你们直接走向了首领的房间");Sleep(1000);
    if(zjj[2]==1&&zjj[3]==1) 
    {   
        bd8();
        return 0;
    }
    Slowsay("换完子弹的你想离开");
    Slowsay("就在你快要离开的时候，妹子抓住了你的手");
    Slowsay("“我喜欢你，别走”,她这样说");
    Slowsay("于是，你留了下来");
    Slowsay("你们的生活是那样的幸福"); 
    Slowsay("直到有一天......");Sleep(1000);
    Slowsay("基地首领希望你去执行一个任务，\n");
    Slowsay("在执行任务的过程中");
    Slowsay("妹子曾被丧尸咬到过一口");
    Slowsay("她以为你没有发现");
    Slowsay("而你却在远处看到了这一幕");
    Slowsay("奇怪的是，她却并没有变异\n");
    Slowsay("那一刹那你突然想起，");
    Slowsay("你们的房间里，总是弥漫着一股血腥的味道......");Sleep(1000);
    Slowsay("Happy End------神仙眷侣");Sleep(1000);
    Slowsay("???????????????????????????????????");
    Slowsay("True End------认清？·妹子");
    if(zjj[3]==0)
    {
        Sleep(2000);
        Slowsay("获得线索-----不变异？·妹子"); 
    }
    zjj[3]=1;Sleep(1000);
}
int td4()
{
    system("cls");
    Slowsay("当丧尸危机爆发时，你正呆在家里\n");
    char ch=_getch();
    if(vv==0) ch=_getch();
        system("cls");
        Slowsay("当丧*#******丧尸危机*$*&*^&*机爆发时，**你正呆***&*爆发******#在家里**\n");Sleep(1000);
    	Slowsay("***检*#******测到*不**丧尸危**88机*$匹*$**机爆发时，**配***#在家里****\n");Sleep(2000);
    	Slowsay("L当****#OG****I危机*$N**E机爆***(RR*8%#404)**发时，**你O*****#在家R里!\n");Sleep(2000);
        system("cls");
    if(vv==0) ch=_getch();
    Slowsay("有什么不对劲");
    Slowsay("你这样想着");
    Slowsay("过去了好多天，\n你还是一个人都没有遇到，\n除了丧尸就是丧尸");
    Slowsay("为什么他们......不见了？");
    Slowsay("\n");
    Slowsay("True End------验证失败");
    zjj[4]=1;
    if(zbbj==0)
        Slowsay("进阶线索-----乱码，废弃与失联"),zbbj=1;Sleep(1000);
}
int td5()
{
    system("cls");
    Slowsay("当少年死去后，整个世界好像变得不同了");
    Slowsay("所有的活人在一瞬间消失");
    Slowsay("所有的丧尸当场去世"); 
    Slowsay("你的眼前只剩下了黑暗");
    Slowsay("不知道过去了多久，你死了");
    Slowsay("Bad End......");Sleep(1000);
    Slowsay("不，还没有结束");
    Slowsay("虽然好像和往常死去之后的感觉一样");
    Slowsay("但是。。。好像。。。");Sleep(1000);
    Slowsay("有延迟？。。。");
    Slowsay("。。。在这段时间里，你的思考一直没停。。。");
    Slowsay("True End-----死亡姗姗来迟");
    s++;
    if(zjj[5]==0)
        Slowsay("进阶线索-----少年之死");
    zjj[5]=1;   Sleep(1000); 
}
int tg3()
{
    Slowsay("当你再次睁开眼时");
    Slowsay("你发现自己躺在一个营养仓内");
    Slowsay("你无比的确认这就是真实的世界");
    Slowsay("脑中的一切开始明晰起来");
    Slowsay("你认为自己知道了一切的真相");
    Slowsay("去杀光人类吧！！！！");
    Slowsay("你这样想着");
    Slowsay("在身着白大褂的丧尸们的欢呼声中");
    Slowsay("你打碎了玻璃，跑出了营养仓");
    Slowsay("来到了外面这个被战争破坏得满目疮痍的世界");
    Slowsay("战火硝烟，炮声隆隆");
    Slowsay("你熟练的发出嘶吼，呼唤着周围的丧尸");
    Slowsay("你指挥着他们，毁掉了一个又一个人类的基地"); 
    Slowsay("最后，在这场世纪战争中，丧尸们艰难地取得了胜利"); 
    Slowsay("作为它们的英雄，你自豪的统治着世界。"); 
    Slowsay("虽然，其实，在那些你不知道的地方");
    Slowsay("一个个一样的营养仓中，装着一个个一样的你。");
    Slowsay("---------------游戏终极剧情通关-------------");
    tongguan1=2; Save(); Sleep(1000);
}
int tg2()
{
    Slowsay("当你再次睁开眼时");
    Slowsay("你发现自己躺在一个营养仓内");
    Slowsay("你无比的确认这就是真实的世界");
    Slowsay("可是你却发现自己没法操纵身体");
    Slowsay("隔着玻璃，一个黑色的身影正在操作着");
    Slowsay("你清晰的看见那个人的大脑裸露出来，与你的接在一起");
    Slowsay("这时，又有一大波记忆涌入脑海。");
    Slowsay("“少年与妹子......是以“成功者”“英雄”“神话传说”为原型创造的人物......”");
    Slowsay("“游戏中的情节与场景......取材于现实世界真实案例......”");
    Slowsay("再往后，你的脑中一片混乱。");
    Slowsay("“...舍弃.........熟练..我....智慧..学习........获得.....”");
    Slowsay("“.....种族...探索.......杀...进化.........帮助..需要.....”");
    Slowsay("“...成熟....兵器.....无敌..下风.......战争...伟大.....英雄.....”");
    Slowsay("激昂的声音一直回荡着。");
    Slowsay("---------------游戏进阶剧情通关-------------"); 
    tongguan1=1; Sleep(1000); 
}
int td6()
{
    Slowsay("一天以后，少年回来了");
    Slowsay("一起回来的还有妹子");
    Slowsay("“找到了......”");
    Slowsay("少年的手中拿着一个破损的铭牌");
    Slowsay("铭牌上的字迹很诡异，但写着熟悉的内容：");
    Slowsay("【22-08-03...】");
    Slowsay("“你的......”");
    Slowsay("妹子神色复杂的看了你一眼");
    Slowsay("“我们是一类人......”");
    Slowsay("“现在，让我把你带出去吧。”");
    if(qxs==1&&swx==0)
    {
        tg2();
        return 0;
    }
    else
    {
        Slowsay("一股强烈的撕扯感出现到了你身上");
        if(swx==1) Slowsay("此时的你，是如此渴望着死亡与结局\n你大笑着张开双臂，迎接了死亡。");
        else Slowsay("此时的你并不能接受如此巨大的伤害"),Slowsay("你死了。");
        Slowsay("Bad End      14");
        if(hjj[14]==0)
            Slowsay("进阶线索-----外面的世界");
        hjj[14]=1;
        s++; 
    }Sleep(1000); 
} 

int bd6()
{
    system("cls");
    Slowsay("你感觉到自己正在变异，");
    Slowsay("意识开始逐渐模糊起来");
    Slowsay("你的肚子正无比渴望着食物，你啃噬着触及的一切！");
    Slowsay("但是不够，你的身躯饿得干枯，你甚至开始食用自己的躯体！");
    Slowsay("接着，你眼前一黑，再也没有醒来......");
    s++;
    hjj[6]=1;
    Slowsay("Bad End      6");Sleep(1000); 
} 

int bd3()
{
    system("cls");
    char ch;
    Slowsay("长久的等待终于让你失去了理智，你疯了。\n");
    Slowsay("Bad End   3\n");
    hjj[3]=1;Sleep(1000); 
    if(mp==-1)
    {
        Slowsay("当政府的救援队打开你家的门时，你嘶吼着扑了上去");
        if(zd>0)
            Slowsay("他们试图将你击毙，却被你提前一枪击倒");
        else
        {
            Slowsay("你被他们击毙了");
            Slowsay("Bad End       12");
            s++;
            hjj[12]=1;
            return 0; 
        }
        Slowsay("你如同一个熟练的猎手，狩猎着救援队");
        Slowsay("当他们全部死去后，你开始享用起你的大餐");
        Slowsay("Bad End           13");
        if(by==0)
            Sleep(2000),Slowsay("进阶线索-----早已变异！·本我"),by=1;
        hjj[13]=1;
        return 0; 
    }
    s++;
}
int bd7()
{
    s++;
    system("cls");
    Slowsay("你，被狗咬死了");
    Slowsay("Bad End      7");
    hjj[7]=1;Sleep(1000); 
}

int bd15()
{s++;
    Slowsay("你发现这笔迹有些不对");
    Slowsay("就好像是新写上去的一样");
    Slowsay("认字迹的话，好像还十分熟悉");  Sleep(1000);  
    Slowsay("正当你想的入迷的时候，你的脖子被咬住了");
    Slowsay("在死前，你隐约听到了少年的声音,“Again.”");
    Slowsay("Bad End     15");
    if(hjj[15]==0)
    {
        Sleep(2000);
        Slowsay("进阶线索-----伪造......");   
    } 
    hjj[15]=1; Sleep(1000); 
}
int tgg3()
{
    system("cls");
    Slowsay("你杀掉了少年，并吃掉了他的尸体");
    Slowsay("世界开始崩塌");
    tg3(); Sleep(1000); 
}
int bd9()
{
    s++;
    system("cls");
    Slowsay("诡异的是，当你杀光了跟来的丧尸后，发现地下室里并没有丧尸");
    Slowsay("这里有的，只是一个穿着白大褂的尸体");
    Slowsay("在尸体的衣服口袋中，你找到了一个笔记本");
    Slowsay("****(无法辨认)1号****进展*****永生**");
    Slowsay("今********，*号诞生了，他比其*****更*");
    Slowsay("有些不对,*****的发育*****太快***");
    Slowsay("2号的**被***出有*****强感染性*****");
    Slowsay("**********************************");
    Slowsay("***瓶颈，或许我们**应该****活体样本");
    Slowsay("**,**样本*****失去活性,*****但**在动\n");
    if(mp==-1)
    {
        bd15();
        return 0;
    } 
    Slowsay("正当你看的入迷的时候，你的脖子被咬住了");
    Slowsay("在死前，你隐约听到了少年的声音,“Again.”");
    Slowsay("Bad End     9");
    if(hjj[9]==0)
    {
        Sleep(2000);
        Slowsay("获得线索-----实验体·1号和2号");   
    } 
    hjj[9]=1;Sleep(1000); 
} 

int tg()
{
    system("cls");
    Slowsay("不知为何，当你走到这里时，感到世界在一瞬间发生了变化");
    Slowsay("你不知道这个变化发生在那里，你只知道，现在的世界十分违和");
    Slowsay("或许，这个世界不是真实的");
    Slowsay("当你的脑中出现了这个的时候，你眼前的世界，蹦塌了");
    Slowsay("于此同时，大量记忆冲进了你的脑海");
    Slowsay("不，它们只是回来了，这本身就是你的记忆");
    Slowsay("他们在一开始被一些虚假的记忆所替换");
    Slowsay("从记忆中，你得知你此时正在玩一个vr游戏");
    Slowsay("少年与妹子则是游戏的npc");
    Slowsay("这款游戏号称有着超强的代入感");
    Slowsay("你在发售当天就买来玩了");
    Slowsay("“这游戏真是了不起啊”,你这样想着，“再玩一次吧”");
    Slowsay("...是啊，没错，这一切只是游戏，游戏。............");Sleep(1000); 
    Slowsay("躺在仓中的你，自始至终，都没有睁开眼。");
    Slowsay("---------------游戏基础剧情通关-------------"); 
    cdd=0;
    tongguan=1;Sleep(1000); 
}
int cg()
{
    system("cls");
    Slowsay("你感觉到违和感在不断加深");
    Slowsay("世界好像不再是真实的");
    Slowsay("你现在脑中只有一种想法\n");Sleep(1000); 
    Slowsay("活下去！越久越好！！！"); Sleep(1000); 
}
int cg2()
{
    system("cls");
    system("Color C");
    Slowsay("违和感在此时已经聚集到了顶峰\n");
    Slowsay("你的脑中想清楚了一切\n");
    Slowsay("1.那么，下一步是  杀光他们\n");
    Slowsay("2.那么，下一步是  团结起来\n");
    x=read();
    if(x==1)
        Slowsay("已立起尸王线flag，接下来，去打通全 15 badend！"),swx=1,qxs=1; 
    else
        Slowsay("“看来你还是没懂啊......”背后传来冷冷的声音\n\n“ A  G  A  I  N   . ”"); 
    system("Color F");Sleep(1000); 
}
int Swx()
{
    system("cls");
    Slowsay("哈。。。哈。。。哈。。。。。。");
    Slowsay("我。。。已经完成了。。。");
    Slowsay("所有的死法。。。我都体验了一遍了。。。");
    Slowsay("我。。。一直是只丧尸吧。。。");
    Slowsay("无论被打倒多少次。。。我都会站起来继续。。。");
    Slowsay("只要是我想通的结局。。。我便一定会通掉它。。。");
    Slowsay("只要是我想杀的人。。。我便一定会杀死他。。。");
    Slowsay("只要是我想知道的真相。。。我便一定会知晓它。");
    Slowsay("我。。。已经不是以前的那个懦弱无能的我了。。。");
    Slowsay("这一轮。。。我。。。要成为王！！！\n");
    Slowsay("在实验室中，为首者发出低哑的嘶吼：");
    Slowsay("所有人员一级戒备！实验，进入最后阶段！！");
    Slowsay("------------终极剧情-尸王线开启！------------");cdd=0;
}
int bd10()
{
    system("cls");
    Slowsay("你发现了另一个基地");
    Slowsay("弹尽粮绝的你选择加入了他们");
    Slowsay("之后的每一天都十分单调");
    Slowsay("外出寻找物资，然后天黑了回家睡觉");
    Slowsay("应该是这样吗？");
    Slowsay("也许吧");
    Slowsay("Bad End     10");
    hjj[10]=1; Sleep(1000); 
}
int hd5()
{
    Slowsay("没关系的，一切都会过去的");
    Slowsay("你这样说的");
    Slowsay("他似乎感觉到了你的善意，一点一点向你靠近");
    Slowsay("你紧紧的抱住了他");
    Slowsay("我会保护好你的"); Sleep(1000); 
    Slowsay("Happy End-----跨越物种的gay~");  Sleep(1000); 
}
int sswj()
{
Save();
    system("cls");
    int w=0;
    mp=0;
    if(tongguan==1&&zjj[4]==0)
    {
        Slowsay("检测到你已通关，是否领取特殊物品\n");
        Slowsay("1.领取");
        Slowsay("2.不领取");
        while(true)
        {
            x=read();
            if(x==1)    
                mp=-1; 
            if(x==2)
            {
                td4();
                return 0;
            }
            break;
        }
    }
    else if(tongguan==1)
    {
        Slowsay("检测到你已通关，已领取特殊物品\n");mp=-1;
    }
    char ch;
    if(cdd==1)
    {
        Slowsay("是否读取存档\n");
        Slowsay("1.读取\n");
        Slowsay("2.不读取\n");
        x=read();
        if(x==1)
        {
            sw=sw1;
            zd=zd1;
            sn=sn1;
            mz=mz1;
            mp=mp1;
            goto cddd1;
        }
    }
    system("cls");
    Slowsay("当丧尸危机爆发时，你正呆在家里\n");if(vv==0) ch=_getch();
    Slowsay("你有10点物资可以分配到子弹和食物上"); 
    if(swx==2) Slowsay("...\n\n但是！不！我已经不会再惧怕食物短缺与丧尸小兵了！\n\n我，应当是世界的王！！\n"),zd=99999,sw=99999;
    else{if(vv==0) ch=_getch();
    int x,y;
    qiang=0;gun=0;zd=0;sw=0;mz=0;mzzd=0;sn=0;mzhg=0;
    Slowsay("\n请输入你的选择(此次输入需键入回车，例：5 5 )\n");
    while(true)
    {
        scanf("%d%d",&x,&y);
        zd=x;sw=y;
        if(x+y!=10||x<0||y<0)
        {
            if(x==666666&&y==5201314)
            {
                Slowsay("启用秘籍\n");
                Slowsay("请输入你真正需要的子弹数和食物数（上限：999 )\n");
        scanf("%d%d",&x,&y);
        zd=min(x,999);sw=min(y,999);
                break;
            }
            Slowsay("请重新输入\n");
            w++;
            if(w>5)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
                Slowsay("行了行了，这只是第一个选择而已\n"), 
                Slowsay("有必要这么皮吗\n"),
                Slowsay("自动分配食物3个子弹7个\n");
                if(vv==0) ch=_getch();
                sw=3,zd=7; 
                break;
            }
        }
        else break;
    }
    }
    Slowsay("你的家里是个较为安全的地方，你可以选择搜索你家的物资或是去邻居家看看\n");
    if(vv==0) ch=_getch();
    Slowsay("1.留在家中\n");
    Slowsay("2.前往邻居家\n"); 
    while(true)
    {
        x=read();
        if(x!=1&&x!=2)
            Slowsay("请重新输入\n");
        else
            if(x==1)
            {if(swx==2) {Slowsay("饿啊！为什么我还呆在家里！！");break;}
            else {
                Slowsay("在二楼，你发现了一些食物食物+3\n");
                if(vv==0) ch=_getch();
                Slowsay("在家里过了一夜，食物-1\n");
                sw=sw+2;
                break;
            }}
            else
            {if(swx==2) {Slowsay("可恶！为什么邻居家里没有人！！");break;}
            else {
                Slowsay("在前往邻居家的路上，你遇到了丧尸\n");
                if(vv==0) ch=_getch(); 
                if(zd<1) 
                {
                    Slowsay("你朝他开了一枪，不过枪里没有子弹，你被他咬死了\n");
                    if(vv==0) ch=_getch(); 
                    hjj[11]=1;
                    Slowsay("Bad End      11\n");
                    s++;
                    if(vv==0) ch=_getch();
                    Slowsay("另外在说一句，一个子弹都不带，还到处乱浪，你是真的作");
                    return 0;
                }
                else
                {
                    Slowsay("你用你手中的枪结束了他的生命，子弹-1\n");
                    zd=zd-1;
                    if(vv==0) ch=_getch();
                    Slowsay("邻居家里不知为何并没有人，你在仔细搜索后发现了一个弹夹，里面有4发子弹\n");
                    zd+=4;
                    if(vv==0) ch=_getch();
                    Slowsay("在邻居家过了一夜后，食物-2\n");
                    sw=sw-2;
                    if(sw<0)
                    {
                        esl();
                        return 0; 
                    } 
                }
                break;
            }}
    }
    if(vv==0) ch=_getch();
    qp();
    Slowsay("你回想起这附近有一座商场，你决定\n");
    if(vv==0) ch=_getch();
    Slowsay("1.前往商场\n");
    Slowsay("2.到处乱走\n");
    Slowsay("3.留在屋子里\n");
    while(true)
    {
        x=read();
        if(x!=1&&x!=2&&x!=3)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        if(swx==2&&x==1) {system("cls"),Slowsay("你循着残存的记忆前往商场，找到了适合你膨胀体型的衣服，可以继续隐藏下去。\n\n"),mz=1;break;}
        else if(swx==2&&x==2) {system("cls"),Slowsay("你到处乱走，见人即杀，丧尸与人类的血混合着溅满了街道，\n惨叫连连，火光接天，如同末世一般。\n你站在尸山上狂笑，不屑于看那些渺小的灵魂。\n\n然而，你丝毫没有注意，一个娇小的身影远远的看到了你，捂着嘴逃之夭夭。\n\n"),mz=10086;break;}
        else if(swx==2&&x==3) {system("cls");Slowsay("你如一名老练的猎手忍耐着饥饿，终于等来了敲门声。\n你得意洋洋的屠杀着这送上门来的大餐\n并跟踪着逃兵进入了幸存者基地。\n那一天，残阳似血，为浸染大地的红再镶上一道道金光。\n\n");Sleep(1000);return 0;} 
        else if(x==3)
        {
            if(sw<2) 
            {
                esl();
                return 0;
            }
            Slowsay("无聊正在逐渐消磨你的意志，但你还是坚持了下来。食物-2\n");
            sw=sw-2;
            if(vv==0) ch=_getch();
            Slowsay("之后的每一天你都是这样，独自一人在家中等待救援\n");
            if(vv==0) ch=_getch();
            Slowsay("在过了好久之后\n");cout<<mp; 
            if(sw<6)
            {
                esl();
                return 0;
            }
            x=rand()%2;
            if(x==1&&mp==0) {hd1();return 0; }
            else {bd3();return 0;}
        }
        else if(x==2)
        {       
            int xx=rand()%3;
            if(xx!=0)
            {
                Slowsay("在到处乱走的过程中，你遇到了来自世界各地的丧尸,子弹-2\n");
                if(zd<2)
                {
                    mzd();
                    return 0;
                }
                zd=zd-2;
            }
            else
            {
                Slowsay("在到处乱走的过程中，你走入了一处曾为战场的废墟\n");
                if(vv==0) ch=_getch();
                Slowsay("你循着硝烟味，终于找到了军队残留的弹药箱,子弹+6\n");
                zd+=6;
            }
            break;
        }
        else if(x==1)
        {
            if(zd<4)
            {
                mzd();
                return 0;
            }
            Slowsay("在前往商场的过程中，你遇到了丧尸,子弹-4\n");
            zd=zd-4;
            if(vv==0) ch=_getch();
            Slowsay("你在商场发现了食物与子弹,食物+3,子弹+2\n"); 
            sw=sw+3;zd=zd+2;
            break;
        }
    }
    if(mz!=10086)
    {Slowsay("你在回家的路上发现了一个女幸存者\n");
    if(vv==0) ch=_getch();
    Slowsay("她试图向你讨要食物，你的选择是\n");
    Slowsay("1.不给\n");
    Slowsay("2.给她2份食物\n");
    Slowsay("3.给她2份子弹\n");
    Slowsay("4.给她一枪\n");
    while(true)
    {
        x=read();
        if(x<1||x>4)
        {
            Slowsay("请重新输入。\n");
            continue;   
        }   
        if(x==1)
        {
            Slowsay("妹子生气的走了。\n");
            if(vv==0) ch=_getch();
        }
        if(x==2)
        {
            if(sw<2)
            {
                Slowsay("食物不足\n");
                continue;
            }
            sw=sw-2;
            mzhg++;
            Slowsay("你的食物-2，妹子好感度+1\n");
            if(vv==0) ch=_getch();
        }
        if(x==3)
        {
            if(zd<2)
            {
                Slowsay("子弹不足\n");
                continue;
            }
            mzzd=1;
            Slowsay("你给了妹子两份子弹，妹子离开了\n"),zd=zd-2;
            if(vv==0) ch=_getch();
        }
        if(x==4)
        {
            if(zd<1)
            {
                Slowsay("子弹不足\n");
                continue;
            }
            zd=zd-1;
            Slowsay("你一枪杀死了妹子，并从她的尸体上找到了4份食物\n");
            sw=sw+4;
            mzhg=-1;
            if(swx==2) Slowsay("你吃掉了妹子的尸体，真是人间佳肴！\n"),mzhg=-10086;
        }
        if(swx==2&&x!=4) Slowsay("你看着妹子的背影在心中狂笑\n"),mzhg=10086;
        break;
    }}
    Slowsay("又过了一夜，你的食物-2\n");
    if(vv==0) ch=_getch();
    qp();
    sw=sw-2;
    if(sw<0)
    {
        esl();
        return 0; 
    }
    if(mzhg==1) Slowsay("那个妹子又来找到了你，并邀请你加入他们的幸存者基地\n");
    else Slowsay("你在附近发现了一个幸存者基地\n");
    if(swx!=2){
    Slowsay("在前往基地的途中，你遇到了丧尸\n");
    Slowsay("你且战且退，大量丧尸把你逼进了一家商店\n");
    Slowsay("门口的丧尸越来越多，你选择\n");
    Slowsay("1.杀出去\n");
    Slowsay("2.守在这\n");
    while(true)
    {
        x=read();
        if(x<1||x>2)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        if(x==1)
        {
            int res=0;
            if(mzhg>0)
                res=1;
            else res=3;
            if(zd<res)
            {
                mzd();
                return 0;
            }
            zd=zd-res;
            printf("你消耗了一些子弹冲了出去，子弹-%d\n",res);
            if(mzzd==1&&mp==-1)
            {
                Slowsay("妹子在她杀死的丧尸的尸体上找到了许多物资，子弹+7，食物+3\n");
                zd=zd+7;sw=sw+3;
                mz=1;
                break;
            }
            x=rand()%5;
            if(res==1&&x!=3)
                Slowsay("妹子为了帮你突围，被丧尸咬到，然后自杀了。\n"),mzhg=-1; 
            if(x==3&&res==1)
            {
                td3();
                return 0;
            }
        }
        else
        if(x==2)
        {
            if(zd<5)
            {
                mzd();
                return 0;
            }
            zd=zd-5;
            Slowsay("你守在这家商店里直到杀死了所有找来的丧尸,子弹-5\n"); 
            if(mzhg==1)
            {
                Slowsay("妹子在商店中发现了一把无限子弹的枪，子弹+10086\n");
                zd=10086;
                if(vv==0) ch=_getch();
                Slowsay("但是妹子在翻找货架的时候被沾了丧尸血的货架划伤\n");
                Slowsay("妹子自杀了\n");
                mzhg=-1; 
            }
        }
        break;
    }}
    if(vv==0) ch=_getch();
    qp();
    Slowsay("你来到了这个幸存者基地\n");
    if(mz==10086) {system("cls");Slowsay("人们在一位年轻首领的带领下顽强的与你战斗\n每个人都在尽自己的努力去守卫基地\n哪怕战友们一个个倒下\n哪怕首领被你愤怒的捏爆脑袋\n没有一个人放弃战斗，没有一个人抛弃希望\n\n最后，奇迹出现了\n\n在基地的废墟中，你的尸体沉重的倒下。\n\n");s++;Sleep(1000);return 0;}
    Slowsay("这个基地的首领表示可以用子弹交换你手中的食物\n");
    printf("你还有%d份食物，%d份子弹\n",sw,zd);
    if(vv==0) ch=_getch();
    Slowsay("请输入你需要的子弹数(0-9)\n");
    while(true)
    {
        x=read();
        if(x<0||x>sw)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        sw=sw-x;
        zd=zd+x;
        if(x>=1)
        {
            Slowsay("首领很开心你能提供稀缺的食物，多给了你1份子弹\n");
            zd=zd+2;
        }
        break;
    }
    if(vv==0) ch=_getch();
    qp();
    Slowsay("又过了一天，食物-2");
    sw=sw-2;
    if(sw<0)
    {
        esl();
        return 0;
    }
    if(vv==0) ch=_getch();
    system("cls");
    Slowsay("基地首领希望你加入这个基地\n");
    Sleep(500);
    Slowsay("你的选择是\n");
    Sleep(500);
    system("Color C");
    Slowsay("1.留在这");
    Slowsay("2.离开");
    while(true)
    {
        x=read();
        if(x<1||x>2)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        system("Color F");
        if(swx==2&&x==1){system("cls");Slowsay("在一个月黑风高的夜里，你终于忍不住袭击了营地。\n年轻首领被你梦中封喉。\n人们顽强的与你战斗\n每个人都在尽自己的努力去守卫基地\n没有一个人放弃战斗，没有一个人抛弃希望\n但是他们失败了。\n在基地的废墟中，英雄们的尸体沉重的倒下。\n\n而你狂笑着吞噬着一切。\n\n");Sleep(1000);return 0;}
        else if(x==1)
        {
            if(mzhg>-1) hd2();
            else hd3(); 
            return 0;
        }
        else if(x==2)
        {
            Slowsay("你决定\n");
            Slowsay("1.当天离开\n");
            Slowsay("2.再停留一天\n"); 
            while(true)
            {
                x=read();
                if(x<1||x>2)
                {
                    Slowsay("请重新输入\n");
                    continue;
                }
                if(x==1) break;
                if(x==2)
                {
                      if(vv==0) ch=_getch();
                     qp();
                    Slowsay("这个基地的首领表示可以用子弹交换你手中的食物\n");
                    printf("你还有%d份食物，%d份子弹\n",sw,zd);
                    if(vv==0) ch=_getch();
                    Slowsay("请输入你需要的子弹数\n");
                    while(true)
                    {
                        x=read();
                        if(x<0||x>sw)
                        {
                            Slowsay("请重新输入\n");
                            continue;
                        }
                        sw=sw-x;
                        zd=zd+x;
                        if(x>=3)        
                        {
                            Slowsay("首领很开心你能提供稀缺的食物，多给了你3份子弹\n");
                            zd=zd+3;
                        }
                        break;
                    }
                    sw=sw-2;
                    if(sw<0)
                    {
                        esl();
                        return 0;
                    }
                    Slowsay("又过了一夜，食物-2\n"); 
                }
                break;
            }
            Slowsay("在你离开的时候，一个少年跑了过来。\n");
            Slowsay("他说，他想要和你一起走\n");
            Slowsay("1.带上他\n");
            Slowsay("2.不带他\n");
            while(true)
            {
                x=read();
                if(x<1||x>2)
                {
                    Slowsay("请重新输入\n");
                    continue;
                }
                if(x==2)
                {
                    Slowsay("少年生气的离开了");
                    if(swx!=2) Slowsay("，当他走远了，你才发现\n\n在刚刚的接触中，他偷走了你所有的子弹\n");
                    else Slowsay("\n当你走远后，你才发现，少年一直冷笑着跟在你的身后\n"),sn=1;
                    zd=0;
                }
                if(x==1)
                {
                    Slowsay("你选择上少年一起走\n");
                    Slowsay("少年将他身上带着的一份食物交给了你\n");
                    sw=sw+1;
                    Slowsay("食物消耗+1，少年入队\n");
                    sn=1;
                }
                break;
            }
        }
        break;
    }
    if(vv==0) ch=_getch();
    qp();
    printf("你在路边的一座没人的房子里过了一夜,食物-%d\n",2+sn);
    sw=sw-2-sn;
    if(vv==0) ch=_getch();
    if(sn==1&&swx==2)
    {
        Slowsay("\n1.杀了少年，这时没人可以阻止你！\n");
        Slowsay("2.我决定在少年面前一直隐瞒到底\n");
        x=read();
        if(x==1){Slowsay("少年不见了，难道他发现了......\n\n你一回头，少年咯咯笑着咬住你的脖子\n\n你应该等我虚弱时再下手啊.....\n\n");s++;return 0;}
    }
    if(sw<0)
    {
        esl();
        return 0;
    }
    Slowsay("是否存档？\n");
    Slowsay("1.存档（记录当前进度，只能有一个存档）\n");
    Slowsay("2.不存\n");
    x=read();
    if(x==1)
    {
        cdd=1;
        sw1=sw;
        zd1=zd;
        mp1=mp;
        mz1=mz;
        sn1=sn;
        Slowsay("存档成功");
    }
cddd1:
    qp();
    if(sn==1)
    {
        vv=0;
        Slowsay("今天一早你就被少年叫醒了，\n");
        if(vv==0) ch=_getch();
        Slowsay("他在床底下发现了一箱方便面，食物+8\n");
        sw=sw+8;
        Slowsay("少年向你讨要武器，你决定\n");
        Slowsay("1.把枪给他\n");
        Slowsay("2.把捡到的水管给他\n");
        Slowsay("3.什么都不给他\n");
        while(true)
        {
            x=read();
            if(x<1||x>3)
            {
                Slowsay("请重新输入\n");
                continue;
            }
            if(x==1) gun=0,qiang=2;
            if(x==2) gun=2,qiang=1;
            if(x==3) gun=0,qiang=1;
            break;
        }
    }
    else
    {
        Slowsay("你在冰箱里发现了几包巧克力\n");
        if(vv==0) ch=_getch();
        Slowsay("希望它们还没过期吧,食物+3\n");
        sw=sw+3;
    }
    if(vv==0) ch=_getch();
    Slowsay("今天你们来到了一家大商场\n");
    Slowsay("你决定\n");
    Slowsay("1.独自探索1楼\n");
    Slowsay("2.独自探索2楼\n");
    if(sn==1)
    {
        Slowsay("3.和少年一起探索2楼");
    }
    while(true)
    {
        x=read();
        if(x<1||x>3)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        if(x==1)
        {
            Slowsay("你在一楼发现了一些子弹，子弹+3\n");
            zd=zd+3;
            Slowsay("奇怪的是，一只丧尸都没有看到\n");
            if(vv==0) ch=_getch(); 
            if(sn>0)
            {
                if(qiang==2)
                {
                    Slowsay("当你来到二楼时，发现了一地尸体\n");
                    Slowsay("少年就倒在这尸体中间，他死前手还紧紧握着枪\n");
                    Slowsay("你把枪拿了回来，并在少年的尸体下面发现了一箱压缩饼干\n");
                    Slowsay("食物+10086\n");
                    if(vv==0) ch=_getch();
                    sw=10086;
                    if(sw>10000&&zd>9000) 
                    {
                        td();
                        return 0;
                    }
                    sn=0;
                    qiang=1;
                }
                else
                {
                    Slowsay("当你来到二楼时，发现了少年的尸体\n");
                    if(vv==0) ch=_getch();sn=0;
                    Slowsay("你紧紧握着手中的枪，猛地一回头\n");
                    Slowsay("四周大量的丧尸向你涌来\n");
                    if(vv==0) ch=_getch();
                    zd=zd-5;
                    if(zd<0)
                    {
                        mzd();
                        return 0;
                    }
                    Slowsay("你杀光了这些丧尸，子弹-5\n");
                    if(vv==0) ch=_getch();
                    Slowsay("你在二楼找到了食物，食物+3\n");
                    sw+=3;
                }
            }
        }
        if(x==2)
        {
            Slowsay("你来到了二楼，数之不尽的丧尸忽然从阴影中窜出\n");
            if(qiang==2)
            {
            Slowsay("尽管你没了枪也尽力抵抗，可丧尸的数量实在太多。\n");
                mzd();
                return 0;
            }
            if(vv==0) ch=_getch();
            zd-=5;
            if(zd<0)
            {
            Slowsay("尽管你尽力抵抗，可丧尸的数量实在太多。\n");
                mzd();
                return 0;
            }
            Slowsay("你杀光了这些丧尸，子弹-5\n");
            if(vv==0) ch=_getch();
            Slowsay("你在二楼找到了食物，食物+3\n");
            sw+=3;
            if(sn==1)
            {
                Slowsay("少年在一楼找到了子弹，子弹+3\n");
                zd=zd+3;
            }
        }
        if(x==3&&sn==1)
        {
            system("cls");
            Slowsay("你们来到了二楼\n"); 
            if(vv==0) ch=_getch();
            system("Color C");
            Slowsay("数之不尽的丧尸从阴影中窜出");
            Slowsay("尽管你们尽力抵抗，可丧尸的数量实在太多。");
            if(gun!=2&&qiang!=2)
            {
                Slowsay("没有武器的少年被当场咬死。");
                if(mp==-1&&mz==0)
                {
                    td5();
                    return 0;
                }
                sn=0;   
            }
            Slowsay("其中一只丧尸趁你不注意冲到了你的旁边");
            if(gun==2) Slowsay("就在你要被咬死的时候，少年扔出了手中的水管\n，救下了你");
            else if(qiang!=2)
            {
                zd=zd-3;
                if(zd<0)
                {
                    mzd();
                    return 0;
                }
                Slowsay("你赶忙回头几枪补掉了这只丧尸,子弹-3");
            }
            zd=zd-3;
            if(qiang==2||zd<0)
            {
                system("Color F"); 
                mzd();
                return 0;
            }
            system("Color F"); 
            Slowsay("经过了一番苦战，你们终于战胜了所有丧尸，子弹-3");
            if(vv==0) ch=_getch();
        }
        break;
    }
    if(vv==0) ch=_getch();
    qp();
    if(vv==0) ch=_getch();
    printf("又过了一夜，食物-%d\n",sn+2);
    sw=sw-2-sn;
    if(sw<0)
    {
        esl();
        return 0;
    }
    qp();
    Slowsay("今天在出门的时候\n");
    Slowsay("你遇到了一条流浪狗\n");
    Slowsay("1.用枪打死它\n");
    Slowsay("2.用食物打发它\n");
    while(true)
    {
        x=read();
        if(x<1||x>2)
        {
            Slowsay("请重新输入\n");
            continue;
        }
        if(x==1)
        {
            zd=zd-1;
            if(zd<0)
            {
                bd7();
                return 0;
            }
            Slowsay("你一枪打死了这条狗，子弹-1\n");
            if(sn==0) break;
            Slowsay("在打死了狗之后，你忽然发现少年的脸色不太好\n");
            if(vv==0) ch=_getch();
            Slowsay("原来，在昨天的商场中，少年早就被咬了一口");
            Slowsay("他一直瞒着你，不敢说出来");
            Slowsay("此时，他闻到了血腥味，看到了尸体，已经忍不住，濒临变异了！！");
            Slowsay("你决定\n");
            Slowsay("1.杀了他\n");
            Slowsay("2.不杀他\n");int a3=0;
            if(gjj[4]==1&&zd<4)
            {
                Slowsay("3.安抚他\n");a3=1;
            }
            while(1)
            {
                x=read();
                if(x<1||x>3||(x==3&&a3==0))
                {
                    Slowsay("请重新输入\n");
                    continue;
                }
                if(x==1)
                {
                    if(swx==2)
                    {
                        if(mzhg<-1000) tgg3();
                        else Slowsay("\n“杀我还早的很呢......”\n\n少年咯咯笑着挡下了你所有的攻击\n\n“因为你还不是一个优秀的丧尸......”"),Sleep(1000),mzd();
                        return 0;
                    }
                    if(vv==0) ch=_getch();
                    if(mp==-1&&mz==0)
                    {
                        Slowsay("奇怪的是，你直接秒掉了他。\n");Sleep(1000); 
                        sn=0;
                        td5();
                        return 0;
                    }
                    else if(mp==-1&&mz!=0)
                    {
                        Slowsay("突然，妹子出现了。\n");
                        Slowsay("“放着我来！”，妹子与少年搏斗起来，妹子的力气极大，竟然真的压制住了少年！\n");
                        Slowsay("在你的惊恐目光下，少年的皮肤渐渐变淡，重新变回了“人”！\n");
                        Slowsay("这时，你才注意到少年的声音一直带着点沙哑，如同低吼一般\n");
                        Slowsay("“我没事。”他说。\n");
                    }
                    else
                    {
                    system("Color C");
                    Slowsay("你试着向他开枪，子弹穿过了他的身体\n");
                    Slowsay("你十分惊恐，疯狂地倾泻着手中的弹药\n");
                    Slowsay("“没有用的。”少年咯咯笑着向你走进，\n");
                    Slowsay("而他的伤口却以肉眼可见的速度愈合！\n");
                    Slowsay("怎么可能！怎么可能，怎么可能......\n");
                    system("Color F");
                        mzd();
                        if(zjj[9]==0)
                        {
                            Slowsay("获得线索-----无敌变异！·少年\n");Sleep(1000);
                            zjj[9]=1;
                        }
                        return 0;
                    }
                }
                if(x==2)
                {
                    system("Color C");
                    Slowsay("你看着少年变异\n");
                    Slowsay("奇怪的是，他变异后并没有像其他的丧尸一样，向你扑过来\n");
                    Slowsay("而是躲在墙角瑟瑟发抖\n");
                    Slowsay("你慢慢的走过去\n");
                    Slowsay("就在你走近的时候，少年突然暴起\n");
                    Slowsay("狠狠地咬住了你的手臂\n");
                    Slowsay("你赶忙用枪打死他，可是为时已晚\n");
                    system("Color F");
                    sn=0;
                    if(sw>=6){td2();return 0;}
                    else{bd6();return 0;}
                }
                break;
            }
            if(x==3&&gjj[4]==1)
            {
                gjj[5]=1;
                hd5();
                return 0;
            }
        }
        if(x==2)
        {
            sw=sw-1;
            if(sw<0){bd7();return 0;}
            Slowsay("你用一份食物引开了这条狗，食物-1\n");
        }
        break;
    }if(swx==2)
    {system("cls");if(sn==1) Slowsay("少年的变异的很突然，但身为丧尸的你没有受到攻击\n你们结伴一起狩猎着人类\n只是，与少年相处的越久，你就越发感受到他的强大。\n你只好收起杀心跟在他后面。\n应该是这样吗？"),Sleep(1000),Slowsay("\n\n“我错过了机会”\n"); 
    else Slowsay("少年死后，你无聊的屠杀着一切，\n在接下来的几天里，你轻松的杀掉了城中所有的生物\n之后，你只能天天游荡，无助的面对着这座死城\n应该是这样吗？\n"),Sleep(1000),Slowsay("\n“我走错了路。”");
    Sleep(1000);return 0;} 
    if(vv==0) ch=_getch();
    if(sn==1&&sw>=4&&gun==2&&zd>5){hd4();return 0;}
    if(sn==1)
    {
        Slowsay("又过了一天，食物-2\n");
        sw=sw-2;
        if(sw<0){esl();return 0;}
        if(vv==0) ch=_getch();
            system("cls");
        Slowsay("今天早上，你发现少年不见了\n");
        Slowsay("你决定\n");
        Slowsay("1.去寻找他\n");
        Slowsay("2.不去找他\n");
        while(true)
        {
            x=read();
            if(x<1||x>2)
            {
                Slowsay("请重新输入\n");
                continue;
            } 
            if(x==1)
            {
            system("cls");qp(); 
                Slowsay("你通过蛛丝马迹一路追踪，来到了一座大厦前\n");
                Slowsay("在路上，你遭遇了丧尸，子弹-2\n");
                zd=zd-2;
                if(zd<0)
                {
                    mzd();
                    return 0;   
                }
                Slowsay("你决定\n");
                system("Color C");
                Slowsay("1.破门！冲入大厦\n");
                Slowsay("2.悄悄开门，潜入大厦\n");
                Slowsay("3.寻找其它的入口\n");
                while(true)
                {
                    x=read();
                    if(x<1||x>3)
                    {
                        Slowsay("请重新输入\n");
                        continue;
                    }
                    if(x==1)
                    {
                        int xx=rand()%4; 
                        Slowsay("你进入大厦才发现这里几乎充满了丧尸！");
                        Slowsay("丧尸似乎被你惊醒，如同海啸般向你涌来！");
                        system("Color F");
                        if(zd>6) Slowsay("怎么回事！！你一路且战且退来到了地下室"),zd-=6,bd9();
                        else if(xx==0) Slowsay("幸运的是，你退后的脚碰到了地下室的暗门，Thanks God!"),bd9();
                        else Sleep(1000),mzd();
                        return 0;
                    }
                    if(x==2)
                    {
                        int xx=rand()%6;
                        Slowsay("你进入大厦才发现这里几乎充满了丧尸！");
                        system("Color F");
                        Slowsay("怎么回事！！你害怕得定在原地，奇怪的是它们并没有向你扑来，只是疲惫的看着你。");
                        Slowsay("定睛一看，丧尸们个个躯体畸形，断手断脚者不乏其数");
                        Slowsay("再一看，这些丧尸们被奇怪的机器束缚，不得踏出大厦一步。");
                        Slowsay("你大着胆子靠近一个丧尸，发现它的头上有着模糊的字迹");
                        Slowsay("【21.7.29，失败】");Sleep(1000); 
                        Slowsay("瞬间，那个丧尸惊恐地捂住头上的字，发出奇怪的吼声！");
                        Slowsay("其它丧尸如同被激怒，海啸般向你涌来！");
                        if(zd>6) Slowsay("怎么回事！！你一路且战且退来到了地下室"),zd-=6,bd9();
                        else if(xx==0) Slowsay("幸运的是，你退后的脚碰到了地下室的暗门，Thanks God!"),bd9();
                        else Sleep(1000),mzd();
                        return 0;
                    }
                    if(x==3)
                    {
                        system("Color F");
                        Slowsay("你走入刚刚的大街，你的老相识开心地吐着舌头看着你");
                        Slowsay("......后面跟着它的一堆朋友......");
                        Slowsay("......你被讨食的狗狗们追着跑过了两条大街，不停地扔出食物来减缓它们的攻势......");
                        if(sw>5) Slowsay("终于，它们全部满足的趴倒在了地上。\n领头狗如同可以听懂人话一样，将你带到了一个隐蔽的地道口前......"),sw-=5,bd9();
                        else bd7();
                        return 0;
                    }
                    break;
                }
            }
            break;
        }
    }
    qp();
    if(vv==0) ch=_getch();
    if(mz==1&&sn==1&&swx==0){td6();return 0;}
    Slowsay("又过了一天,食物-2");
    sw=sw-2;if(sw<0){esl();return 0;}
    Sleep(500);
    Slowsay("遭遇丧尸，子弹-3");
    zd=zd-3;if(zd<0){mzd();return 0;}   
    Sleep(500);
    Slowsay("又过了一天,食物-2");
    sw=sw-2;if(sw<0){esl();return 0;}
    Sleep(500);
    Slowsay("遭遇丧尸，子弹-2");
    zd=zd-2;if(zd<0){mzd();return 0;}   
    Sleep(500);
    if(ccg==1){tg(); return 0;}
    else{bd10();return 0;}
}
int main()
{
    srand(time(0));
    Read();
    int go=0;
    while(tongguan1!=2)
    {
        int v=0;
        char ch;
        mp=0;
        if(go==1){
        Sleep(1000);
        if(vv==0) ch=_getch();
        system("cls");Save();}go=1;
        Slowsay("1.进行游戏\n");
        Slowsay("2.查看成就\n");
        Slowsay("3.查看线索(获得全部线索后通关游戏)\n");
        Slowsay("4.获得一条随机的提示\n");
        Slowsay("5.游戏相关\n");
        Slowsay("6.极速模式\n");
        Slowsay("7.退出游戏\n");
        x=read();
        if(x==1)
        { 
            sswj();
            if(s>50&&swhm==0)
            {
                swhm=1;
                Slowsay("又死了啊......");
                Slowsay("这已经是第几次了呢......");
                Slowsay("一个柔和的声音从耳边传来");
                Slowsay("或许早该放弃了");Sleep(1000);
                Slowsay("获得线索-----计数者");
            }
        } 
        if(x==2)
        {
            int v1=0;
            system("cls");
            if(tongguan1==2) Slowsay("\n已通关终极剧情\n");
            if(tongguan1==1) Slowsay("\n已通关进阶剧情（进阶不重要！终极才是王道！）\n");
            if(tongguan==1) Slowsay("\n已通关基础剧情\n");
            int v=0;
            Slowsay("\nHappy Bnd 达成\n");
            if(gjj[1]==1) Slowsay("苟到最后\n");else Slowsay("未达成\n"); 
            if(gjj[2]==1) Slowsay("神仙眷侣\n");else Slowsay("未达成\n"); 
            if(gjj[3]==1) Slowsay("英雄不朽\n");else Slowsay("未达成\n"); 
            if(gjj[4]==1) Slowsay("认清自己\n");else Slowsay("未达成\n"); 
            if(gjj[5]==1) Slowsay("跨越物种的gay\n");else Slowsay("未达成\n"); 
            Slowsay("\n");
            Slowsay("Bad End 达成(共15个)\n");
            for(int i=1;i<=17;i++)
                if(hjj[i]==1)
                    printf("%d ",i),v1++;
            if(v1>=15&&swx==1)
                swx=2,cdd=0,Swx();
            Slowsay("\n");
            printf("当前死亡次数:%d",s);
            Slowsay("\n");
            Slowsay("True End 达成\n");
            if(zjj[1]==1) Slowsay("拯救世界\n");else Slowsay("未达成\n");   
            if(zjj[3]==1) Slowsay("认清？·妹子\n");else Slowsay("未达成\n");  
            if(zjj[2]==1) Slowsay("认清！·本我\n"); else Slowsay("未达成\n");  
            if(zjj[4]==1) Slowsay("验证失败\n");else Slowsay("未达成\n");  
            if(zjj[5]==1) Slowsay("死亡姗姗来迟\n");else Slowsay("未达成\n");  
            Slowsay("\n");
            if(vv==0) char ch=_getch();
        }
        if(x==3)
        {
            system("cls");
            int v=0;
            Slowsay("基础线索\n");
            if(zjj[1]==1) Slowsay("    奇特的枪与饼干\n"),v++;else Slowsay("    ？？？？？\n");
            if(zjj[2]==1) Slowsay("    延迟变异？·少年\n"),v++;else Slowsay("    ？？？？？\n");
            if(zjj[9]==1) Slowsay("    无敌变异！·少年\n"),v++;else Slowsay("    ？？？？？\n");
            if(zjj[3]==1) Slowsay("    不变异？  ·妹子\n"),v++; else Slowsay("    ？？？？？\n");
            if(hjj[8]==1) Slowsay("    早已变异！·妹子\n"),v++; else Slowsay("    ？？？？？\n");
            if(hjj[9]==1) Slowsay("    实验体·1号和2号\n"),v++; else Slowsay("    ？？？？？\n");
            if(v>=6&&ccg==0)
            {
                Sleep(2000);
                cdd=0;cg();ccg=1;
            }
            Slowsay("进阶线索\n");
            if(swhm==1) Slowsay("    计数者\n"),v++; else Slowsay("    ？？？？？\n");
            if(zbbj==1) Slowsay("    乱码，废弃与失联\n"),v++; else Slowsay("    ？？？？？\n");
            if(by==1) Slowsay("    早已变异！·本我\n"),v++; else Slowsay("    ？？？？？\n");
            if(hjj[15]==1) Slowsay("    伪造......\n"),v++; else Slowsay("    ？？？？？\n"); 
            if(zjj[5]==1) Slowsay("    少年之死\n"),v++; else Slowsay("    ？？？？？\n");
            if(hjj[14]==1) Slowsay("    外面的世界\n"),v++; else Slowsay("    ？？？？？\n");
            if(v>=12&&qxs==0)
            {
                Sleep(2000);
                cg2();cdd=0;Sleep(1000);
                Slowsay("-------- 游戏进阶结局已解锁（快前往达成吧）--------");qxs=1;
            }
            if(vv==0) ch=_getch();
        } 
        if(x==4)
        {
            system("cls");
            int y=rand()%3;
            if(y==0){Slowsay("【稀有提示】"); x=rand()%14;
            if(x==0) Slowsay("【稀有结局提示】 试试 0 10 开局！");
            else if(x==1) Slowsay("【稀有结局提示】 最好的爱总要先错过~");
            else if(x==2) Slowsay("【剧情提示】 二周目：少年变异后有新剧情！");
            else if(x==3) Slowsay("【剧情提示】 不变异的妹子总有一天会在营地暴露！再来一遍！");
            else if(x==4) Slowsay("【剧情提示】 弹尽粮绝之时，变异的少年会记起上辈子的爱情！再来一遍！");
            else if(x==5) Slowsay("【剧情提示】 第二天，和首领换更多子弹，他会更开心！");
            else if(x==6) Slowsay("【剧情提示】 在家里等待疯掉？再来一遍！");
            else if(x==7) Slowsay("【剧情提示】 二周目：再次进入实验室吧！");
            else if(x==8) Slowsay("【剧情提示】 二周目：神枪手妹子...");
            else if(x==9) Slowsay("【剧情提示】 二周目：不带子弹！等待救援！");
            else if(x==10) Slowsay("【通关方式】 二周目：在获得所有线索后前往“外面的世界”。");
            else if(x==11) Slowsay("【通关方式】 三周目：（都提示这么明显了）吃掉妹子，杀掉少年。");
            else if(x==12) Slowsay("【线索提示】 死亡很多次后......(有个地方可以刷死亡次数)");
            else Slowsay("【？？？】 666666,5201314（会错过一些线索与结局！）");
            }else{x=rand()%14;
            if(x==0) Slowsay("加了好感后，妹子有几率不死");
            else if(x==1) Slowsay("少年喜欢子弹");
            else if(x==2) Slowsay("乱走有时可以获得子弹");
            else if(x==3) Slowsay("冲进去活下来几率更大");
            else if(x==4) Slowsay("分头探商店可以获得更多资源");
            else if(x==5) Slowsay("有一些结局只能通关后触发");
            else if(x==6) Slowsay("有一些结局要脸好才能触发");
            else if(x==7) Slowsay("有一些结局要通其他结局后才能触发");
            else if(x==8) Slowsay("大多数时候，你认为一个地方没有好结局只是因为你食物/子弹不够"); 
            else if(x==9) Slowsay("绝大多数的线索来自结局");
            else if(x==10) Slowsay("三大重叠剧情线路：普通，进阶，尸王线");
            else if(x==11) Slowsay("本游戏是一个剧情严谨，人物丰满，细思极恐的好！游！戏！~");
            else if(x==12) Slowsay("事实证明剧情游戏是最难调的！有Bug一定要去博客说出来啊！(luogu.com.cn/blog/z1e2k3i4/)");
            else Slowsay("完成目标后，需要在线索，成就界面开启新剧情哦");
            }
            if(vv==0) char ch=_getch();continue;
        }
        if(x==5)
        {
            system("cls");
            Slowsay("作者：小小小苗\n");
            Slowsay("改错，调试，搬运，游玩：胎神大大（就是在游戏论坛翻到的宝藏而已emm......）\n");
        }
        if(x==6)
        {
            system("cls");
            if(vv==0) vv=1,Slowsay("已开启极速模式");
            else vv=0,Slowsay("已关闭极速模式");
        }
        if(x==7)
        {
            system("cls");
            Slowsay("想退？死吧！！");s++; 
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    Slowsay("Thanks for playing......");Sleep(1000); 
    Slowsay("您已通关，我亲爱的 终极丧尸，成功者，杀人机器，你还没杀够吗？......");system("Color C"); 
}

#include<bits/stdc++.h>
#include<Windows.h> 
#define $ 0.5
//#define int long long
using namespace std;
double sxkz[20][20]={//[������][������]
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
{1,1,1,1,1,1,$,1,0,$,1,1,1,1,1,1,1,1,1},
{1,2,1,$,$,1,2,$,0,2,1,1,1,1,$,2,1,2,$},
{1,1,2,1,1,1,$,2,1,$,1,1,2,$,1,1,1,1,1},
{1,1,1,1,$,$,$,1,$,0,1,1,2,1,1,1,1,1,2},
{1,1,1,0,2,1,2,$,1,2,2,1,$,2,1,1,1,1,1},
{1,1,$,2,1,$,1,2,1,$,2,1,1,1,1,2,1,1,1},
{1,1,$,$,$,1,1,1,$,$,$,1,2,1,2,1,1,2,$},
{1,0,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,$,1},
{1,1,1,1,1,1,2,1,1,$,$,$,1,$,1,2,1,1,2},
{1,1,1,1,1,1,$,2,1,2,$,$,2,1,1,2,$,1,1},
{1,1,1,1,1,2,2,1,1,1,2,$,$,1,1,1,$,1,1},
{1,1,1,$,$,2,2,$,1,$,$,2,$,1,1,1,$,1,1},
{1,1,1,2,1,0,1,1,1,1,1,2,$,$,1,1,$,1,1},
{1,1,2,1,2,1,1,1,1,$,1,1,1,1,$,1,1,0,1},
{1,1,1,2,1,2,1,1,1,$,$,$,2,1,1,$,2,1,1},
{1,1,1,1,1,1,1,1,1,$,1,1,1,1,1,1,2,1,0},
{1,1,$,1,1,1,1,1,2,1,1,1,1,1,2,1,1,$,$},
{1,1,2,1,$,1,1,1,1,$,$,1,1,1,1,1,2,2,1},
};
//�ն��ɶ����ҳ��ֻ�ˮ�ݵ糬��������
struct Skill
{
	string name;
	int type;//1:a,2:sa,3:change
	int shuxing;
	int attack;
	int hit_rate;
};
struct pokemon
{
	string name;
	int shuxing[3];
	int HP,hp,a,p,sa,sp,s;
	int eff_a=0,eff_p=0,eff_sa=0,eff_sp=0,eff_s=0;
	Skill skill[5];
	bool seed=false;
	string statu="";
	int statu_time=0;
}pm[1000];
map<int,double> change;
void insert(int num,string name,int sx1,int sx2,int HP,int a,int p,int sa,int sp,int s)
{
	pm[num].name=name;
	pm[num].shuxing[1]=sx1;
	pm[num].shuxing[2]=sx2;
	pm[num].HP=pm[num].hp=HP;
	pm[num].a=a;
	pm[num].p=p;
	pm[num].sa=sa;
	pm[num].sp=sp;
	pm[num].s=s;
}
void Insert(Skill &a,string name,int type,int shuxing,int attack,int hit_rate)
{
	a.name=name;
	a.type=type;
	a.shuxing=shuxing;
	a.hit_rate=hit_rate;
	a.attack=attack;
}
void init()
{
	insert(6,"�����",10,3,153,105,98,129,105,120);
	insert(94,"����",8,4,135,85,80,150,95,130); 
	insert(248,"�����˹",6,17,175,154,130,115,120,81);
	insert(257,"���漦",10,2,155,140,90,130,90,100);
	insert(260,"���ӹ�",11,5,175,130,110,105,110,80);
	insert(376,"�޽��",9,14,155,155,150,115,110,90);
	insert(497,"������",12,0,150,95,115,95,115,133);
	insert(445,"��ҧ½��",16,5,183,150,115,100,105,122);
	
	Insert(pm[6].skill[1],"������",1,10,120,100);
	Insert(pm[6].skill[2],"��������",2,3,75,95);
	Insert(pm[6].skill[3],"��֮����",2,16,85,100);
	Insert(pm[6].skill[4],"��֮��",3,16,0,0);
	Insert(pm[94].skill[1],"��Ӱ��",2,8,80,100);
	Insert(pm[94].skill[2],"����ը��",2,4,90,100);
	Insert(pm[94].skill[3],"ʮ�����",2,13,90,100);
	Insert(pm[94].skill[4],"������",2,12,90,100);
	Insert(pm[248].skill[1],"��ʯ����",1,6,100,80);
	Insert(pm[248].skill[2],"ҧ��",1,17,80,100);
	Insert(pm[248].skill[3],"����",1,5,100,100);
	Insert(pm[248].skill[4],"��֮��",3,16,0,0);
	Insert(pm[257].skill[1],"������",1,10,120,100);
	Insert(pm[257].skill[2],"�׵�ȭ",1,13,75,100);
	Insert(pm[257].skill[3],"������",1,2,80,70);
	Insert(pm[257].skill[4],"����",1,5,100,100);
	Insert(pm[260].skill[1],"����",1,11,80,100);
	Insert(pm[260].skill[2],"����",1,5,100,100);
	Insert(pm[260].skill[3],"����ȭ",1,15,75,100);
	Insert(pm[260].skill[4],"˯��",3,1,0,0);
	Insert(pm[376].skill[1],"����ȭ",1,9,90,90);
	Insert(pm[376].skill[2],"�۴�",1,2,100,90);
	Insert(pm[376].skill[3],"����ͷ��",1,14,80,90);
	Insert(pm[376].skill[4],"�����ƶ�",3,14,0,0);
	Insert(pm[497].skill[1],"��Ҷ�籩",2,12,130,90);
	Insert(pm[497].skill[2],"�ռ���ȡ",2,12,75,100);
	Insert(pm[497].skill[3],"��֮����",2,16,85,100);
	Insert(pm[497].skill[4],"��������",3,12,0,90);
	Insert(pm[445].skill[1],"����",1,5,100,100);
	Insert(pm[445].skill[2],"����",1,16,95,100);
	Insert(pm[445].skill[3],"�ұ�",1,6,75,90);
	Insert(pm[445].skill[4],"����",3,1,0,0);
	
	change[-6]=0.25,change[-5]=0.29,change[-4]=0.33;
	change[-3]=0.4,change[-2]=0.5,change[-1]=0.67;
	change[0]=1.0;
	change[1]=1.5,change[2]=2.0,change[3]=2.5;
	change[4]=3.0,change[5]=3.5,change[6]=4.0;
}
void show()
{
	cout<<"6.�����"<<endl;
	cout<<"94.����"<<endl;
	cout<<"248.�����˹"<<endl;
	cout<<"257.���漦"<<endl;
	cout<<"260.���ӹ�"<<endl;
	cout<<"376.�޽��"<<endl;
	cout<<"445.��ҧ½��"<<endl;
	cout<<"497.������"<<endl;
	cout<<""<<endl;
}
void ability(pokemon p)
{
	cout<<p.name<<": Lv.50";
	if(p.statu!="") cout<<"    ("<<p.statu<<")";
	printf("\n");
	printf("HP:%d/%d\n",p.hp,p.HP);
	printf("�﹥:%d��%.2lf=%d (%d)\n",p.a,change[p.eff_a],int(double(p.a)*change[p.eff_a]),p.eff_a);
	printf("���:%d��%.2lf=%d (%d)\n",p.p,change[p.eff_p],int(double(p.p)*change[p.eff_p]),p.eff_p);
	printf("�ع�:%d��%.2lf=%d (%d)\n",p.sa,change[p.eff_sa],int(double(p.sa)*change[p.eff_sa]),p.eff_sa);
	printf("�ط�:%d��%.2lf=%d (%d)\n",p.sp,change[p.eff_sp],int(double(p.sp)*change[p.eff_sp]),p.eff_sp);
	printf("�ٶ�:%d��%.2lf=%d (%d)\n",p.s,change[p.eff_s],int(double(p.s)*change[p.eff_s]),p.eff_s);
	printf("\n");
}

pokemon p1,p2;
int a,b;

void fight_p1()
{
	cout<<"P1."<<p1.name<<"����"<<endl; 
	cout<<"1."<<p1.skill[1].name<<endl;
	cout<<"2."<<p1.skill[2].name<<endl;
	cout<<"3."<<p1.skill[3].name<<endl;
	cout<<"4."<<p1.skill[4].name<<endl;
	int p1do;
	scanf("%d",&p1do);
	if(p1.skill[p1do].type==1)
	{
		int hit=rand()%100;
		if(hit<p1.skill[p1do].hit_rate)
		{
			double shanghai=(110.0/250)*((double(p1.a)*change[p1.eff_a])/(double(p2.p)*change[p2.eff_p]))*p1.skill[p1do].attack+2;
			double sxjc=sxkz[p1.skill[p1do].shuxing][p2.shuxing[1]]*sxkz[p1.skill[p1do].shuxing][p2.shuxing[2]];
			if(p1.skill[p1do].shuxing==p1.shuxing[1]||p1.skill[p1do].shuxing==p1.shuxing[2]) sxjc*=1.5;
			if(p1.statu=="Burned") shanghai*=0.5;
			p2.hp-=floor(shanghai*sxjc);
			cout<<p1.name<<"��"<<p2.name<<"�����"<<floor(shanghai*sxjc)<<"�˺�"<<endl;
			if(sxjc>1) printf("Ч�����ѣ�\n");
			else if(sxjc<1) printf("����Ч������......\n");
		}
		else cout<<"û������"<<p2.name<<"��"<<endl;
	}
	else if(p1.skill[p1do].type==2)
	{
		int hit=rand()%100;
		if(hit<p1.skill[p1do].hit_rate)
		{
			double shanghai=(110.0/250)*((double(p1.sa)*change[p1.eff_sa])/(double(p2.sp)*change[p2.eff_sp]))*p1.skill[p1do].attack+2;
			double sxjc=sxkz[p1.skill[p1do].shuxing][p2.shuxing[1]]*sxkz[p1.skill[p1do].shuxing][p2.shuxing[2]];
			if(p1.skill[p1do].shuxing==p1.shuxing[1]||p1.skill[p1do].shuxing==p1.shuxing[2]) sxjc*=1.5;
			p2.hp-=floor(shanghai*sxjc);
			cout<<p1.name<<"��"<<p2.name<<"�����"<<floor(shanghai*sxjc)<<"�˺�"<<endl;
			if(sxjc>1) printf("Ч�����ѣ�\n");
			else if(sxjc<1) printf("����Ч������......\n");
		}
		else cout<<"û������"<<p2.name<<"��"<<endl;
	}
	else if(p1.skill[p1do].type==3)
	{
		if(p1.skill[p1do].name=="��֮��")
		{
			if(p1.eff_a<6&&p1.eff_s<6)
			{
				p1.eff_a++,p1.eff_s++;
				cout<<p1.name<<"���﹥���ٶȸ�������1����"<<endl;
			}
			else cout<<p1.name<<"���﹥���ٶ��޷��������ˣ�"<<endl;
		}
		if(p1.skill[p1do].name=="˯��")
		{
			p1.statu="sleep";
			p1.hp=p1.HP;
			cout<<p1.name<<"��״̬�ָ��ˣ�"<<endl;
		}
		if(p1.skill[p1do].name=="�����ƶ�")
		{
			if(p1.eff_s<=5)
			{
				p1.eff_s+=2;
				cout<<p1.name<<"���ٶ�������2����"<<endl;
			}
			else cout<<p1.name<<"���ٶ��޷��������ˣ�"<<endl;
		}
		if(p1.skill[p1do].name=="��������")
		{
			int hit=rand()%10;
			if(hit&&p2.shuxing[1]!=12&&p2.shuxing[2]!=12)
			{
				p2.seed=1;
				cout<<p2.name<<"�����������ӣ�"<<endl;
			}
			else cout<<"û������"<<p2.name<<"��"<<endl;
		}
	}
	if(p1.skill[p1do].name=="������")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p2.statu="Burned";
			cout<<p2.name<<"�������ˣ�"<<endl;
		}
	}
	else if(p1.skill[p1do].name=="����ȭ")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p2.statu="Frozen";
			cout<<p2.name<<"�������ˣ�"<<endl;
		}
	}
	else if(p1.skill[p1do].name=="��Ҷ�籩"&&p1.name=="������")
	{
		p1.eff_sa+=2;
		cout<<"�����ߵ��ع�������2����"<<endl;
	}
	else if(p1.skill[p1do].name=="������")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p2.eff_sp-=1;
			cout<<p2.name<<"���ط�������1����"<<endl;
		}
	}
	else if(p1.skill[p1do].name=="����ը��")
	{
		int hit=rand()%100;
		if(hit<30)
		{
			p2.statu="Poisoned";
			cout<<p2.name<<"�ж��ˣ�"<<endl;
		}
	}
	else if(p1.skill[p1do].name=="ʮ�����"||p1.skill[p1do].name=="�׵�ȭ")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p2.statu="Paralyzed";
			cout<<p2.name<<"������ˣ�"<<endl;
		}
	}
	else if(p1.skill[p1do].name=="ҧ��")
	{
		int hit=rand()%100;
		if(hit<20)
		{
			p2.eff_p--;
			cout<<p2.name<<"�ķ���������1����"<<endl;
		}
	}
	Sleep(2000);
}
void fight_p2()
{
	cout<<"P2."<<p2.name<<"����"<<endl; 
	cout<<"1."<<p2.skill[1].name<<endl;
	cout<<"2."<<p2.skill[2].name<<endl;
	cout<<"3."<<p2.skill[3].name<<endl;
	cout<<"4."<<p2.skill[4].name<<endl;
	int p2do;
	scanf("%d",&p2do);
	if(p2.skill[p2do].type==1)
	{
		int hit=rand()%100;
		if(hit<p2.skill[p2do].hit_rate)
		{
			double shanghai=(110.0/250)*((double(p2.a)*change[p2.eff_a])/(double(p1.p)*change[p1.eff_p]))*p2.skill[p2do].attack+2;
			double sxjc=sxkz[p2.skill[p2do].shuxing][p1.shuxing[1]]*sxkz[p2.skill[p2do].shuxing][p1.shuxing[2]];
			if(p2.skill[p2do].shuxing==p2.shuxing[1]||p2.skill[p2do].shuxing==p2.shuxing[2]) sxjc*=1.5;
			if(p2.statu=="Burned") shanghai*=0.5;
			p1.hp-=floor(shanghai*sxjc);
			cout<<p2.name<<"��"<<p1.name<<"�����"<<floor(shanghai*sxjc)<<"�˺�"<<endl;
			if(sxjc>1) printf("Ч�����ѣ�\n");
			else if(sxjc<1) printf("����Ч������......\n");
		}
		else cout<<"û������"<<p1.name<<"��";
	}
	else if(p2.skill[p2do].type==2)
	{
		int hit=rand()%100;
		if(hit<p2.skill[p2do].hit_rate)
		{
			double shanghai=(110.0/250)*((double(p2.sa)*change[p2.eff_sa])/(double(p1.sp)*change[p1.eff_sp]))*p2.skill[p2do].attack+2;
			double sxjc=sxkz[p2.skill[p2do].shuxing][p1.shuxing[1]]*sxkz[p2.skill[p2do].shuxing][p1.shuxing[2]];
			if(p2.skill[p2do].shuxing==p2.shuxing[1]||p2.skill[p2do].shuxing==p2.shuxing[2]) sxjc*=1.5;
			p1.hp-=floor(shanghai*sxjc);
			cout<<p2.name<<"��"<<p1.name<<"�����"<<floor(shanghai*sxjc)<<"�˺�"<<endl;
			if(sxjc>1) printf("Ч�����ѣ�\n");
			else if(sxjc<1) printf("����Ч������......\n");
		}
		else cout<<"û������"<<p1.name<<"��"<<endl;
	}
	else if(p2.skill[p2do].type==3)
	{
		if(p2.skill[p2do].name=="��֮��")
		{
			if(p2.eff_a<6&&p2.eff_s<6)
			{
				p2.eff_a++,p2.eff_s++;
				cout<<p2.name<<"���﹥���ٶȸ�������1����"<<endl;
			}
			else cout<<p2.name<<"���﹥���ٶ��޷��������ˣ�"<<endl;
		}
		if(p2.skill[p2do].name=="˯��")
		{
			p2.statu="sleep";
			p2.hp=p2.HP;
			cout<<p2.name<<"��״̬�ָ��ˣ�"<<endl;
		}
		if(p2.skill[p2do].name=="�����ƶ�")
		{
			if(p2.eff_s<=5)
			{
				p2.eff_s+=2;
				cout<<p2.name<<"���ٶ�������2����"<<endl;
			}
			else cout<<p2.name<<"���ٶ��޷��������ˣ�"<<endl;
		}
		if(p2.skill[p2do].name=="��������")
		{
			int hit=rand()%10;
			if(hit&&p1.shuxing[1]!=12&&p1.shuxing[2]!=12)
			{
				p1.seed=1;
				cout<<p1.name<<"�����������ӣ�"<<endl;
			}
			else cout<<"û������"<<p1.name<<"��"<<endl;
		}
	}
	if(p2.skill[p2do].name=="������")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p1.statu="Burned";
			cout<<p1.name<<"�������ˣ�"<<endl;
		}
	}
	else if(p2.skill[p2do].name=="����ȭ")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p1.statu="Frozen";
			cout<<p1.name<<"�������ˣ�"<<endl;
		}
	}
	else if(p2.skill[p2do].name=="��Ҷ�籩"&&p2.name=="������")
	{
		p2.eff_sa+=2;
		cout<<"�����ߵ��ع�������2����"<<endl;
	}
	else if(p2.skill[p2do].name=="������")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p1.eff_sp-=1;
			cout<<p1.name<<"���ط�������1����"<<endl;
		}
	}
	else if(p2.skill[p2do].name=="����ը��")
	{
		int hit=rand()%100;
		if(hit<30)
		{
			p1.statu="Poisoned";
			cout<<p1.name<<"�ж��ˣ�"<<endl;
		}
	}
	else if(p2.skill[p2do].name=="ʮ�����"||p2.skill[p2do].name=="�׵�ȭ")
	{
		int hit=rand()%100;
		if(hit<10)
		{
			p1.statu="Paralyzed";
			cout<<p1.name<<"������ˣ�"<<endl;
		}
	}
	else if(p2.skill[p2do].name=="ҧ��")
	{
		int hit=rand()%100;
		if(hit<20)
		{
			p1.eff_p--;
			cout<<p1.name<<"�ķ���������1����"<<endl;
		}
	}
	Sleep(2000);
}
void Max()
{
	if(p1.hp>p1.HP) p1.hp=p1.HP;
	if(p2.hp>p2.HP) p2.hp=p2.HP;
	if(p1.eff_a>6) p1.eff_a=6;
	if(p1.eff_p>6) p1.eff_p=6;
	if(p1.eff_sa>6) p1.eff_sa=6;
	if(p1.eff_sp>6) p1.eff_sp=6;
	if(p1.eff_s>6) p1.eff_s=6;
	if(p2.eff_a>6) p2.eff_a=6;
	if(p2.eff_p>6) p2.eff_p=6;
	if(p2.eff_sa>6) p2.eff_sa=6;
	if(p2.eff_sp>6) p2.eff_sp=6;
	if(p2.eff_s>6) p2.eff_s=6;
}

signed main()
{
	init();
	show();
	cout<<"P1: ";
	scanf("%d",&a);
	cout<<"P2: ";
	scanf("%d",&b);
	p1=pm[a],p2=pm[b];
	while(p1.hp>0&&p2.hp>0)
	{
		system("cls.");
		ability(p1);ability(p2);
		if(p1.statu=="sleep")
		{
			cout<<p1.name<<"����˯��......"<<endl;
			fight_p2();
		}
		else if(p2.statu=="sleep")
		{
			cout<<p2.name<<"����˯��......"<<endl;
			fight_p1();
		}
		else if(p1.statu=="Frozen")
		{
			cout<<p1.name<<"�������ˣ��޷�ʹ����ʽ��"<<endl;
			fight_p2();
		}
		else if(p2.statu=="Frozen")
		{
			cout<<p2.name<<"�������ˣ��޷�ʹ����ʽ��"<<endl;
			fight_p1();
		}
		else if(p1.statu=="Paralyzed")
		{
			cout<<p1.name<<"������ˣ��޷�ʹ����ʽ��"<<endl;
			fight_p2();
		}
		else if(p2.statu=="Paralyzed")
		{
			cout<<p1.name<<"������ˣ��޷�ʹ����ʽ��"<<endl;
			fight_p1();
		}
		else if(double(p1.s)*change[p1.eff_s]>double(p2.s)*change[p2.eff_s])
		{
			cout<<endl<<p1.name<<"���ٶȸ���"<<endl;
			fight_p1();
			if(p1.hp<0||p2.hp<0) break;
			fight_p2();
		}
		else
		{
			cout<<endl<<p2.name<<"���ٶȸ���"<<endl;
			fight_p2();
			if(p1.hp<0||p2.hp<0) break;
			fight_p1();
		}
		if(p1.seed)
		{
			int sh=floor(double(p1.HP)/8);
			p1.hp-=sh;
			p2.hp+=sh;
			cout<<p1.name<<"����ȡ��������"<<endl;
			Sleep(1500);
		}
		else if(p2.seed)
		{
			int sh=floor(double(p2.HP)/8);
			p2.hp-=sh;
			p1.hp+=sh;
			cout<<p2.name<<"����ȡ��������"<<endl;
			Sleep(1500);
		}
		if(p1.statu=="Burned")
		{
			p1.hp-=floor(double(p1.HP)/16);
			cout<<p1.name<<"�ܵ������յ��˺���"<<endl;
			Sleep(1500);
		}
		if(p2.statu=="Burned")
		{
			p2.hp-=floor(double(p1.HP)/16);
			cout<<p2.name<<"�ܵ������յ��˺���"<<endl;
			Sleep(1500);
		}
		if(p1.statu=="Poisoned")
		{
			p1.hp-=floor(double(p1.HP)/8);
			cout<<p1.name<<"�ܵ��˶����˺���"<<endl;
			Sleep(1500);
		}
		if(p2.statu=="Poisoned")
		{
			p2.hp-=floor(double(p2.HP)/8);
			cout<<p2.name<<"�ܵ��˶����˺���"<<endl;
			Sleep(1500);
		}
		if(p1.statu=="sleep"&&p1.statu_time>=2) p1.statu="",cout<<p1.name<<"�����ˣ�"<<endl;
		if(p2.statu=="sleep"&&p2.statu_time>=2) p2.statu="",cout<<p2.name<<"�����ˣ�"<<endl;
		if(p1.statu=="Burned"&&p1.statu_time>=5) p1.statu="",cout<<p1.name<<"������״̬����ˣ�"<<endl;
		if(p2.statu=="Burned"&&p2.statu_time>=5) p2.statu="",cout<<p2.name<<"������״̬����ˣ�"<<endl;
		if(p1.statu=="Frozen"&&p1.statu_time>=5) p1.statu="",cout<<p1.name<<"�ı���״̬����ˣ�"<<endl;
		if(p2.statu=="Frozen"&&p2.statu_time>=5) p2.statu="",cout<<p2.name<<"�ı���״̬����ˣ�"<<endl;
		if(p1.statu=="Poisoned"&&p1.statu_time>=5) p1.statu="",cout<<p1.name<<"���ж�״̬����ˣ�"<<endl;
		if(p2.statu=="Poisoned"&&p2.statu_time>=5) p2.statu="",cout<<p2.name<<"���ж�״̬����ˣ�"<<endl;
		
		if(p1.statu!="") p1.statu_time++;
		if(p2.statu!="") p2.statu_time++;
		Max();
	}
	if(p1.hp>0) cout<<"P1."<<p1.name<<"��ʤ��"<<endl;
	else if(p2.hp>0) cout<<"P2."<<p2.name<<"��ʤ��"<<endl;
	return 0;
}

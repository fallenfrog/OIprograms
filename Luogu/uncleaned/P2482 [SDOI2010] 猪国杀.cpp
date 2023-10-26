#include<bits/stdc++.h>
using namespace std;
struct Pig{
	queue<char> cards;
	int self,HP = 4,nxt;
	bool enemy[10],zg = 0;
}p[10];
int n,m,fz;
queue<char> h;
map<char,int> kind;
void init();
void game();
void print();

int main(){
	init();
	game();
	print();
	
	return 0;
}

void init(){
	kind['P'] = kind['K'] = kind['D'] = 0;
	kind['N'] = kind['F'] = kind['W'] = kind['J'] = 1;
	kind['Z'] = 2;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;char c;
		cin >> s;
		switch(s[0]){
			case 'M': p[i].self = 0;break;
			case 'Z': p[i].self = 1;break;
			case 'F': p[i].self = -1;break;
		}
		for(int i=0;i<4;i++){
			cin >> c;
			p[i].cards.push(c);
		}
	}
}

void game(){
	bool mw = false,fw = false;
	int i = 0;
	while(!mw && !fw){
		if(p[i].HP>0){
			for(int i=0;i<2;i++){
				if(h.size()==1)
					h.push(h.front());
				p[i].cards.push(h.front());
				h.pop();
			}
			switch(p[i].self){
				case 0:break;//这里没做完 
					
			}
		}
		i = (i+1)%n;
	}
}

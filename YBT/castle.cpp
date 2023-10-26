#include<iostream>
#include<cstdio>
using namespace std;

int m,n;

struct Room{
	int north,south,east,west,tot;
	
	void init(tot){
		//将总墙数分解填入各墙数 
		south = tot/8;
		east = (tot%8)/4;
		north = (tot%4)/2;
		west = tot%2;
	}
}rooms[50][50];

int main(){
	freopen("castle.out","w",stdout);
	freopen("castle.in","r",stdin);
	
	//初始化各房间 
	cin >> m >> n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> rooms[i][j].tot;
			rooms[i][j].init();
		}
	}
	
	//测试 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d%d%d%d ",rooms[i][j].east;rooms[i][j].south;rooms[i][j].west;rooms[i][j].north);
		}
		cout << endl;
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}

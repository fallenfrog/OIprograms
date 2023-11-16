#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "cube";
const int N = 2e6 + 2;

int n, tx, ty, tz, mx, mn;
int i;
struct node{
	int x, y, z;
}nd[N];

void wwc(){
	puts("NO");
	exit(0);
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> nd[i].x >> nd[i].y >> nd[i].z;
	
	//z test
	sort(nd + 1, nd + n + 1, [](node a, node b){return a.x == b.x ? (a.y == b.y ? a.z < b.z : a.y < b.y) : a.x < b.x;});
	tx = nd[1].x, ty = nd[1].y, mx = mn = nd[1].z;
	for(i = 2; i <= n && nd[i].x == tx && nd[i].y == ty; i ++){
		if(nd[i].z != mx + 1)  wwc();
		mx ++;
	}
	if(i <= n)  tx = nd[i].x, ty = nd[i].y, tz = nd[i ++].z;
	for(; i <= n; i ++){
		if(nd[i].x != tx){
			if(tz != mx)  wwc();
			tx = nd[i].x;
			tz = nd[i].z;
			if(tz != mn)  wwc();
			if(nd[i].y != ty)  ty = nd[i].y;
			continue;
		}
		if(nd[i].y != ty){
			if(tz != mx)  wwc();
			ty = nd[i].y;
			tz = nd[i].z;
			if(tz != mn)  wwc();
			if(nd[i].x != tx)  tx = nd[i].x;
			continue;
		}
		if(nd[i].z != tz + 1)  wwc();
		tz ++;
	}
	
	//y test
	sort(nd + 1, nd + n + 1, [](node a, node b){return a.x == b.x ? (a.z == b.z ? a.y < b.y : a.z < b.z) : a.x < b.x;});
	tx = nd[1].x, tz = nd[1].z, mx = mn = nd[1].y;
	for(i = 2; i <= n && nd[i].x == tx && nd[i].z == tz; i ++){
		if(nd[i].y != mx + 1)  wwc();
		mx ++;
	}
	if(i <= n)  tx = nd[i].x, ty = nd[i].y, tz = nd[i ++].z;
	for(; i <= n; i ++){
		if(nd[i].x != tx){
			if(ty != mx)  wwc();
			tx = nd[i].x;
			ty = nd[i].y;
			if(ty != mn)  wwc();
			if(nd[i].z != tz)  tz = nd[i].z;
			continue;
		}
		if(nd[i].z != tz){
			if(ty != mx)  wwc();
			ty = nd[i].y;
			tz = nd[i].z;
			if(ty != mn)  wwc();
			if(nd[i].x != tx)  tx = nd[i].x;
			continue;
		}
		if(nd[i].y != ty + 1)  wwc();
		ty ++;
	}
	
	//x test
	sort(nd + 1, nd + n + 1, [](node a, node b){return a.y == b.y ? (a.z == b.z ? a.x < b.x : a.z < b.z) : a.y < b.y;});
	tz = nd[1].z, ty = nd[1].y, mx = mn = nd[1].x;
	for(i = 2; i <= n && nd[i].z == tz && nd[i].y == ty; i ++){
		if(nd[i].x != mx + 1)  wwc();
		mx ++;
	}
	if(i <= n)  tx = nd[i].x, ty = nd[i].y, tz = nd[i ++].z;
	for(; i <= n; i ++){
		if(nd[i].z != tz){
			if(tx != mx)  wwc();
			tx = nd[i].x;
			tz = nd[i].z;
			if(tx != mn)  wwc();
			if(nd[i].y != ty)  ty = nd[i].y;
			continue;
		}
		if(nd[i].y != ty){
			if(tx != mx)  wwc();
			ty = nd[i].y;
			tx = nd[i].x;
			if(tx != mn)  wwc();
			if(nd[i].z != tz)  tz = nd[i].z;
			continue;
		}
		if(nd[i].x != tx + 1)  wwc();
		tx ++;
	}
	
	puts("YES");

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 1000;
	for(int i = 1; i <= n; i ++){
		system("gen.exe > data.in");
		system("sol.exe < data.in > sol.out");
		system("std.exe < data.in > std.out");
		if(system("fc sol.out std.out")){
			cout << "sb, ը��";
			return 0;
		}
	}
	
	return 0;
}

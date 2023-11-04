#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 1000;
	for(int i = 1; i <= n; i ++){
		system("gen.exe > data.in");
		system("sol.exe < data.in > sol.out");
		system("sb.exe < data.in > sb.out");
		if(system("fc sol.out sb.out")){
			cout << "sb, 炸了";
			return 0;
		}
	}
	cout << "sb, 没问题来对拍";
	
	return 0;
}
//#include<bits/stdc++.h>
//#define INF 0x3f3f3f3f
//using namespace std;
//string str,t,mx,mn;
//int mxn = 0,mnn = INF;
//
//int main(){
//	getline(cin,str);
//	int l = str.size();
//	int i = 0;
//	while(i<l){
//		while(i<l && str[i]!=' ' && str[i]!=','){
//			t.push_back(str[i++]);
//		}
//		if(t.size()>mxn){
//			mxn = t.size();
//			mx = t;
//		}
//		if(t.size()<mnn){
//			mnn = t.size();
//			mn = t;
//		}
//		t = "";
//		i++;
//	}
//	cout << mx << endl << mn;
//	
//	return 0;
//}

#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
char str[205],mx[205],mn[205];
int mxn = 0,mnn = INF,mxl = -1,mnl = -1;

int main(){
	cin.getline(str,sizeof(str));
	int l = strlen(str);
	int i = 0;
	while(i<l){
		int j = i;
		while(j<l && str[j]!=' ' && str[j]!=','){
			j++;
		}
		int tl = j-i;
		if(tl>mxn){
			mxn = tl;
			mxl = i;
		}
		if(tl<mnn){
			mnn = tl;
			mnl = i;
		}
		i = j+1;
	}
	for(int i=mxl;i<mxl+mxn;i++)	printf("%c",str[i]);
	printf("\n");
	for(int i=mnl;i<mnl+mnn;i++)	printf("%c",str[i]);
	printf("\n");
	
	return 0;
}

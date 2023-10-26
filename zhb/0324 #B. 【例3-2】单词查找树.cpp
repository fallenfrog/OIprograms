#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
	char val;
	int child[26];
};
vector<Node> node;
int cnt=1;

int main(){
	node.push_back({' ',{}});
	string str;
	while(cin>>str){
		int i=0;
		for(int w=0;w<str.size();w++){
			int n=str[w]-'A';
			if(node[i].child[n]==0){
				node[i].child[n]=node.size();
				node.push_back({str[w],{}});
				cnt++;
			}
			i=node[i].child[n];
		}
		
		
	}
	printf("%d",cnt);
	
	return 0;
}

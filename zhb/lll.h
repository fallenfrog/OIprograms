#ifndef _LLL_H_
#define _LLL_H_
#include<bits/stdc++.h>
#define L 500
using namespace std;

struct lll{
	int num[1002],len;
	lll(string x=""){
		memset(num,0,sizeof(num));
		len = x.size();
		for(int i=0;i<len;i++)	num[i] = x[len-i-1];
	}
	int &operator [](int i){return num[i];}
	lll operator *(lll other){
		lll pro;
		for(int i=0;i<len;i++){
			for(int j=0;j<other.len;j++){
				pro[i+j] += num[i]*other[j];
			}
		}
		pro.len = min(len+other.len,L);
		int t = 0;
		for(int i=0;i<=pro.len;i++){
			pro[i] += t;
			t = pro[i]/10;
			pro[i] %= 10;
		}
		while(pro[pro.len--]==0);	pro.len += 2;
		return pro;
	}
	lll operator /(lll other){
		lll quo;
		for(int i;;){
		}
	}
};

#endif

#include<bits/stdc++.h>
using namespace std;
set<int> st;

int main(){
	st.insert(1);
	st.insert(2);
	st.insert(4);
	st.insert(6);
	auto minn = st.begin(),maxn = prev(st.end());
	cout << *minn << ' ' << *maxn;
	
	return 0;
}

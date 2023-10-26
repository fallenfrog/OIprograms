#include <bits/stdc++.h>
using namespace std;
char ch[256];
int n = 0,sum = 0;

int main()
{
	memset(ch,' ',sizeof(ch));
	
	while(cin>>ch[n])
	{
		n++;
	}
	
	for(int i=0;i<=254;i++)
	{
		if((int)(ch[i])<=57&&(int)(ch[i])>=48)
			sum++;
	}
		
	printf("%d",sum);
	
	return 0;
}


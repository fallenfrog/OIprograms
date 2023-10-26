#include <iostream>
using namespace std;
int m,n,sum;
bool flag = false,sign = true;

struct Point
{
	int x,y,data;
}a[5][5];
Point k = {-1,-1,-1};

int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin >> a[i][j].data;
			a[i][j].x = i;a[i][j].y = j;
		}
	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(k.data <= a[i][j].data)
				k = a[i][j];
		}
		for(int j=0;j<5;j++)
		{
			if(k.data > a[j][k.y].data)
			{
				sign = false;
			}
		}
		if(sign)
		{
			printf("%d %d %d\n",k.x+1,k.y+1,k.data);
			flag = true;
		}
		sign = true;
		k.data = -1;
	}
	
	if(!flag)
		cout << "not found";
	return 0;
}


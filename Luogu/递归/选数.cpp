#include <iostream>
#include <cmath>
using namespace std;

bool flag[20] = {true};
int num[20];
int sum = 0;
int k;
int n;
int count = 0;

bool isSushu(int x)
{
	bool flag = 1;
	for(int i=2;i < sqrt(x);i++)
		if(x % i == 0)
			flag = 0;
	return flag;
} 


int f(int k_, int sum,int n)
{
	int temp = sum;
	bool flag2[20];
	for(int i = 1;i <=n;i++)
	{
		flag2[i] = flag[i];
	}
	for(int i = 1;i <= n;i++)//
	{
		if(flag[i] == true)//可以选就选 
		{
			sum += num[i];
			flag[i] = false;
			if(k_ == k)//选够了
			{
				cout << sum << endl; 
				if(isSushu(sum))
				{
					count++;
					sum -= num[i];// 回溯 
				}
			}
			else//下选 
				f(k_+1, sum,n);
		}	
	}
	for(int i = 1;i <= n;i++)
	{
		flag[i] = flag2[i];
	}
	sum = temp;
	
	return sum;
}

int main()
{
	cin >> n >> k;
	for(int i=1;i <= n;i++)
		cin >> num[i];
	cout << f(1,sum,n);
	
	return 0;
}

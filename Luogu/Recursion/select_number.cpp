#include <iostream>
#include <cmath>
using namespace std;

int n,k;
int ans = 0;
int num[25];

bool isPrime(int num)
{
    bool flag = 1;
    for(int i = 2;i <= sqrt(num);i++)
    {
        if(num % i == 0)
        {
            flag = 0;
            break ;
        }
    }
    return flag;
}

void dfs(int selected_num,int sum,int startx)
{
    if(selected_num == k)
    {
        if(isPrime(sum))
        {
            ans++;
            return ;
        }
    }
    for(int i = startx;i <= n;i++)
    {
        dfs(selected_num+1,sum+num[i],i+1);
    }
}

int main()
{
    cin >> n >> k;
    for(int i=1;i <= n;i++)
        cin >> num[i];
    dfs(0,0,1);
    cout << ans;

    return 0;
}
#include <iostream>
#include <cmath> 
using namespace std;

bool isprime(int num)
{
	bool flag = 1;
	for(int i=0;i < sqrt(num);i++)
		if(num % i == 0)
		{
			flag = 0;
			break ;
		}
    return flag;
}

int n,k;
int num[25];
long long ans;

void dfs(int m, int sum, int startx){//最重要的递归
//m代表现在选择了多少个数
//sum表示当前的和
//startx表示升序排列，以免算重
    if(m == k){//如果选完了的话
        if(isprime(sum))//如果和是素数
            ans++;//ans加一
        return ;
    }
    for(int i = startx; i < n; i++)
        dfs(m + 1, sum + num[i], i + 1);//递归
        //步数要加一，和也要加
        //升序起始值要变成i+1,以免算重
    return ;//这一个步骤下，所有的都枚举完了
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    dfs(0,0,0);
    cout << ans;
    
    return 0;
}

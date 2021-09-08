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

void dfs(int m, int sum, int startx){//����Ҫ�ĵݹ�
//m��������ѡ���˶��ٸ���
//sum��ʾ��ǰ�ĺ�
//startx��ʾ�������У���������
    if(m == k){//���ѡ���˵Ļ�
        if(isprime(sum))//�����������
            ans++;//ans��һ
        return ;
    }
    for(int i = startx; i < n; i++)
        dfs(m + 1, sum + num[i], i + 1);//�ݹ�
        //����Ҫ��һ����ҲҪ��
        //������ʼֵҪ���i+1,��������
    return ;//��һ�������£����еĶ�ö������
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    dfs(0,0,0);
    cout << ans;
    
    return 0;
}

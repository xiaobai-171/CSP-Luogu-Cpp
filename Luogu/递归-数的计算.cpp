#include<iostream>
using namespace std;

int count = 1;

void f(int n)
{
	for(int i = 1;i <= n/2;i++){
		count++;//ÿ��һ���ͼ�һ 
		f(i);//���������������ǰ��� 
	} 
} 

int main(){
	int n;
    cin>>n;
    f(n);
    cout << count;
    return 0;
}

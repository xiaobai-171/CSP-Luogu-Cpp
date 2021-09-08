#include<iostream>
using namespace std;

int count = 1;

void f(int n)
{
	for(int i = 1;i <= n/2;i++){
		count++;//每上一个就加一 
		f(i);//上了这个还可以在前面加 
	} 
} 

int main(){
	int n;
    cin>>n;
    f(n);
    cout << count;
    return 0;
}

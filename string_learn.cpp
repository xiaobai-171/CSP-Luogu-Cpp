/*
��ƪ��ע�㷨���г�����string�������Լ���������������string֮���ת����
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "this is a test string!";
    string s2 = "this is another test string!";

    /*��ȡһ��string�Ӵ������γ�һ��string--------------------------*/
    // 1��ͨ��string���캯��ʵ�֡�
    string str1(s,0,3);
    cout << "str1: " << str1 << endl;
    // 2��ͨ��substr����ʵ�֡�
    string str2 = s.substr(0,3);
    
    /*�ַ���������������͵�ת��-----------------------------------*/
    /* 1.�ַ���ת�ַ����� */
    char p[20];
    strcpy(p,s.c_str());
    for(int i=0;i < strlen(p);i++){
        cout << p[i];
    }
    cout << "over��" << endl;
                /* 2.�ַ���ת���� */
                int i = stoi("2147483647");
                cout << "number: " << i << endl;
                /*���ܳ�����Χ����Ȼ���򱨴�*/

                string number2 = "2147483648";
                int j = atoi(number2.c_str());
                cout << "number2: " << j << endl;
                /*������Χ�ᵼ��δ�������Ϊ��Ŀǰ��������Ǳ����-2147483648*/

                /* 3.����ת�ַ���-----------------------------------------------*/
                string numstr = to_string(-1233);
                cout << "����ת�ַ��� to_string: " << numstr << endl;
                /*to_string�Ὣ���żӽ���*/

    /* 4.�ַ�����ת���� */
    char a[20];
    itoa(1234,a,10);
    int num = atoi(a);
    cout << "num: " << num << endl;

                /*string +�ŵ�����*/
                s += s2;
                cout << "s (again): " << s << endl;
                s += 'c';
                cout << "s (again2): " << s << endl;
                /*֮��ͷ���ʹ��pop_back , push_back, append ������������*/

    system("pause");
    return 0;
}
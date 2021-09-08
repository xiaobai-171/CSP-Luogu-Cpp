#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        int ans = 0;
        bool sym = true;//;
        
        //取出空格
        int it = 0;
        while(s[it] == ' '){
            it++;
        }
        if(it == s.length()){
            return ans;
        }
        //it到了可能的+，-位
        if(isdigit(s[it])){}
        else{
            if(s[it] == '+'){it++;}
            else if(s[it] == '-'){
                sym = false;
                it++;
            }
            else{
                return ans;
            }
        }
        for(;it < s.length();it++){
            if(!isdigit(s[it])){
                return ans;
            }
            else{
                if(ans > 214'748'364 || (ans == 214'748'364) && (s[it] >= '7')){
                    return 214'748'3647;
                }
                else if(ans < -214'748'364 || (ans == 214'748'364) && (s[it] > '7')){
                    return -214'748'3648;
                }
                ans = sym ? 10 * ans + int(s[it] - '0'): \
                        10 * ans - int(s[it] - '0');
            }
        }


        return ans;
    }

int main(){
    string s = "-9";
    cout << myAtoi(s) << endl;
    system("pause");

    return 0;
}



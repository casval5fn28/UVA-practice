//Postfix
/*我網路上找不到一模一樣題目 所以用打的 考試出過好幾次*/
/*
基本上就是兩個數字後面會配一個符號 然後用這個符號來做運算 會是 + 或是 *
eq. 1 2 + 3 4 + + 
這樣就是 => (1 + 2) + (3 + 4) = 10
eq. 1 2 * 3 4 + *
=> (1 * 2) * ( 3 + 4 ) = 14
//看起來像這題 https://zerojudge.tw/ShowProblem?problemid=f698
但是校內考試只有 + 跟 * 而且每次測資都是單行輸入 所以比較簡單
這個網站好像要考慮其他運算 如果擔心我記錯校內考試的難度 想對照更完整版本的話 可以參考 Postfix_zerojudge.cpp
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<string>

#define ll long long

using namespace std;

int main(){
    string s;
    stack<ll> num;//記好
    getline(cin,s);//記好
    for(ll i=0 ; i<s.length() ; i++){
        if(s[i]==' '){
            continue;
        }
        if(isdigit(s[i])){
            num.push(s[i]-'0');// 語法記得 , 要-'0'!!
        }
        else{
            ll a = num.top();
            num.pop();
            ll b = num.top();
            num.pop();

            if(s[i]=='+'){
                num.push(a+b);
            }
            else if(s[i]=='*'){
                num.push(a*b);
            }
        }
    }
    cout<<num.top();//記得top()!!
    return 0;
}


/*
題解:
這題只要不斷存入數字
一旦遇到運算符號就將最新存入的兩個數字座該符號運算再存回即可

作法:
用 stack 一旦遇到數字就存入
若是遇到運算符號
就先 pop 掉最頂兩個元素
再 push 進運算完的數字
最後印出stack僅存的一個數字即可


*/
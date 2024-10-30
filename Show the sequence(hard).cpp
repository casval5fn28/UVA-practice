//Show the Sequence
//uva 997
//背好 !!!!!
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[200]; // 記好 !!
void parsing(char s[]) {
    int sign = 1, i, tmp_num = 0; // 記好 !!
    char oper;
    for(i = 1; s[i]; i++) { // 範圍記好 !!!!!
        if(s[i] == '-'){
            sign = -1;
        }
        else if(isdigit(s[i])){
            tmp_num = tmp_num * 10 + s[i] - '0';
        }
        else {
            oper = s[i];
            break;// 別忘 !!
        }
    }

    tmp_num *= sign;

    if(oper == '+') {
        parsing(s + i + 1);// 記好 !!
        //整段記好 , 順序注意 !!!
        ll d = a[0];
        a[0] = tmp_num; // 注意 !!!
        for(int i = 1; i < 50; i++) { // 範圍記好 !!
            // 記好 !!!!!! *********
            ll t = a[i];
            a[i] = a[i - 1] + d;
            d = t; 
        }
    }
    else if(oper == '*') {
        parsing(s + i + 1);// 記好 !!
        a[0] *= tmp_num;
        for(int i = 1; i < 50; i++){// 範圍記好 !!
            a[i] *= a[i-1];// *a[i-1]
        }
    }
    else {
        for(int i = 0; i < 50; i++){// 從 0 !!!範圍記好 !!
            a[i] = tmp_num;
        }

    }
}
int main() {
    char s[1024];//用char !!
    int n;
    while(scanf("%s %d", s, &n) == 2) {// 記好 !!
        memset(a, 0, sizeof(a));
        parsing(s);

        for(ll i=0 ;i < n-1;i++){//位置
            cout<< a[i] <<" ";//最後一個後面沒空格
        }
		cout<< a[n-1]<<"\n";
    }
    return 0;
}

/*//Show the Sequence
//uva 997
//背好 !!!!!
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#define ll ll

using namespace std;

void add(ll val, vector<ll>& vec){
    vector<ll> tmp = vec;
    vec[0] = val;
    for(int i = 1 ; i < vec.size() ; i++){
        vec[i] = vec[i-1] + tmp[i-1];//tmp[i-1]
    }
}

void multi(ll val, vector<ll>& vec){
    vector<ll> tmp = vec;
    vec[0] *= val;
    for(int i = 1 ; i < vec.size() ; i++){
        vec[i] = vec[i-1] * tmp[i];//tmp[i]
    }
}

int main(){
    ll num;
    string ipt;

    while(cin>>ipt>>num){
        stack<char> symbol;
        stack<char> opt;
        queue<ll> num_q;

        bool first = 1;
        bool sec = 1;

        vector<ll> series;//number array

        for(ll i = ipt.size()-1 ; i >=0 ; i--){//從最後開始看
            if(ipt[i] == ']'){
                symbol.push(ipt[i]);
            }
            if(ipt[i] == '+' || ipt[i] == '*' ){
                opt.push(ipt[i]);
            }
            if(ipt[i] == '['){//op會在'['前
                symbol.pop();
                if(!sec){
                    if(opt.top() == '*'){
                        multi(num_q.front(),series);//公差,數列
                        num_q.pop();
                    }
                    if(opt.top() == '+'){
                        add(num_q.front(),series);//公比,數列
                        num_q.pop();
                    }
                }
                sec = 0;//位置
            }

            if(isdigit(ipt[i])&& !first){
                num_q.push(ipt[i] - '0');
                if(ipt[i-1] == '-'){
                    num_q.front() *= -1;//記好 !!
                }
            }
            if(isdigit(ipt[i])&& first){
                num_q.push(ipt[i] - '0');
                if(ipt[i-1] == '-'){
                    num_q.front() *= -1;
                }
                series.resize(num,num_q.front());
                num_q.pop();/// 注意 !
                first = 0;
            }
        }
        for(ll i=0 ;i < num-1;i++){//位置
            cout<< series[i] <<" ";//最後一個後面沒空格
        }
		cout<< series[num-1];
		cout<<"\n";
    }
    return 0;
}
*/

//for zero judge version's Postfix
//considering - and / operation

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>

#include<sstream>
#include<string>


#define ll long long

using namespace std;

int main(){

    string s;
    string c;
    while(getline(cin,s)){
        stack<ll> num;
        stringstream ss;
        ss<<s;
        while(ss>>c){
            if(c == "+" || c == "-" || c == "*" || c == "/" ){
            
                ll a = num.top();
                num.pop();
                ll b = num.top();
                num.pop();
            
                if(c=="+")num.push(a+b);
                else if(c=="*")num.push(a*b);
                else if(c=="-")num.push(b-a);//注意 !!
                else if(c=="/")num.push(b/a);//注意 !!
            }
            else{
                num.push(stoi(c));
            }  
        }
        cout<<num.top();//記好 !!
    }
    return 0;
}
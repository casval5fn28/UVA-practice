//Children's Game	
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>//注意
using namespace std;
//得到最大組合數
bool cmp(string a, string b){
    return a+b > b+a;
}

int main(){
    string s;
    int n; 
    while(cin >> n){
        if(n == 0){
            break;
        } 

        vector<string> s_vec;
        while(n--){
            cin >> s;
            s_vec.push_back(s);
        }
        sort(s_vec.begin(), s_vec.end(), cmp);//string能比ascii值
        for(vector<string>::iterator it = s_vec.begin(); it != s_vec.end(); it++){//記得 != s_vec.end() 和 it++
            cout << *it;//注意*
        }
        cout << "\n";//在這         
    }
    return 0;
}
/*
題解:
本題只要將吃進來的多個 string 做大到小排序就可以輕鬆解決

作法:
先將全部數字用 string 的方式吃進 vector
將 vector sort 過一次
排序的邏輯可以自己寫
我的作法是 return a+b > b+a
這樣他就會回傳兩個 string concate 之後大到小的排序順序
最後再全部印出來就好了



*/
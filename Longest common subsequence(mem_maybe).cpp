#include <iostream>
#include <string>
#include <cstring>
#define Maxn 1005
//dp,最小共同子字串
using namespace std;

int table[Maxn][Maxn];// 建議放這 , 不然codeblocks會報錯(OJ不會)

int main(){
    string s1,s2;
    while(getline(cin,s1),getline(cin,s2)){
        memset(table,0,sizeof(table));
        for(int i = 1 ; i <= s1.size(); i++){//從 1 !! , 兩字串分別在最前面加一個空格 , 用 <= !!
            for(int j = 1 ; j <= s2.size() ; j++){//從 1 !! , 兩字串分別在最前面加一個空格 , 用 <= !!
                if(s1[i-1] == s2[j-1]){// 用-1 , 記好
                    table[i][j] = table[i-1][j-1]+1;// 記好 !!!
                }
                else{
                    table[i][j] = max(table[i][j-1],table[i-1][j]);// 記好 !!!
                }
            }
        }
        cout<<table[s1.size()][s2.size()]<<"\n"; //記好 !!
    }
    return 0;
}
/*
題解:
本題只要利用檢查 substring 解法就能解決

作法:
建立一個二維 vector 用來存有 match 到的長度
將兩字串分別在最前面加一個空格

substring 常用解法:
兩層迴圈 如果兩 a[i] 和 b[j] 相等
就將 vector[i][j] 賦值 vector[i-1][j-1] + 1 
若無 則給予 vector[i-1][j] vector[i][j-1] 較大者

最後只要確認 vector 最末格就能知道前字串 match 到後字串的長度
*/
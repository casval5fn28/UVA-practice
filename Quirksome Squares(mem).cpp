//uva 00256
#include<bits/stdc++.h>
using namespace std;

// 建表。
// 每次都只取完全平方數，最多只會到八位數 9999,9999。
// 先求出平方後，再依照不同位數來拆解成兩個數字相加的平方，
// 看會不會跟原先完全平方數相等
int main(){
    int ans[4][10], count[4] = {};//數字記好 !!
    int div[4] = { 10,100,1000,10000 };//數字記好 !!

    for (int i = 0; i < 10000; i++){//數字記好 !!
        int square = i*i;// 平方
        for (int j = 0; j < 4; j++){
            if (i < div[j]){//總位數就不會是 n 了, 10 * 10 = 100 ,100 為 3 位數。
            
                int x = square / div[j] + square % div[j];// 拆解後的 , 記好 !!
                if (x == i){// 完全平方數 , 記好 !!
                    ans[j][count[j]++] = square;// 記好 !!!!!!!*********
                }
            }
        }
    }

    int n;
    while (cin>>n){
        int idx = n / 2 - 1;//記好 !!
        for (int i = 0; i < count[idx]; i++){// count[idx] !!
            cout<<setw(n)<<setfill('0')<<ans[idx][i]<<"\n";//注意 , 輸出位數等於輸入值 !!
        }
    }
    return 0;
}
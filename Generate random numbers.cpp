//uva 11634
#include <bits/stdc++.h>
using namespace std;
//隨機變數，記好
int main() {
    int n, cnt;
    while(cin>>n) {
        if(n == 0){
            break;
        }

        bool visited[10000];//控制長度 , 記好 !!
        memset(visited,false,sizeof(visited));
        cnt = 0;
        while(!visited[n]) {//while not visited , 記好 !!
            cnt++;
            visited[n] = true;//visited , 一定要在這 !!! *****
            //順序記得
            n = n*n;
            n /= 100;
            n %= 10000;//弄完這就得到新數字
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
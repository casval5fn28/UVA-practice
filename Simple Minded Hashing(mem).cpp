#include <bits/stdc++.h>

using namespace std;

//給定長&總和，求符合的嚴格遞增字串數
int dp[30][360][30];//記好 !!

int dfs(int L, int S, int C){
    if (S < 0){
        return 0;
    }
    if (S == 0){
        if (L == 0){
            return 1;
        } 
        else{
            return 0;
        } 
    }
    
    if (L == 0){ // 前者相反
        if (S == 0){
            return 1;
        } 
        else{
            return 0;
        } 
    }

    if (dp[L][S][C] >= 0){ // >= !!
        return dp[L][S][C];
    }

    dp[L][S][C] = 0;//記得!!!!!!!!!!!!!!!!!!!!!!!!
    for (int t = 1; t <= C; t++){//範圍記好 !***********
        dp[L][S][C] += dfs(L - 1, S - t, t - 1);//L - 1, S - t, t - 1 記好 !
    }
    return dp[L][S][C];// 別忘 !!
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);

    int L, S, testcase = 1;//case記得歸0
    memset(dp, -1, sizeof(dp));//用-1 !!!!!!!!!!!!!!
    while (cin >> L >> S){
        if (L == 0 && S == 0){
            break;
        } 
        cout << "Case " << testcase++ << ": "; 
        if (L > 26 || S > 351) {//26:字母量極限 351:總和極限
            cout << "0\n";
        }
        else{
            cout << dfs(L, S, 26) << '\n';// 26 !!
        }
    }
    return 0;
}
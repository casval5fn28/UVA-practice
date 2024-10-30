// Cutting Sticks （切割木棍）
// UVa 10003
// 應用四邊形不等式優化技巧。

#include <bits/stdc++.h>

#define Maxn 51// 數字記一下
#define INF 1e9
#define min(a,b) (a<b?a:b)// 記好 !

using namespace std;

int cut[Maxn], dp[Maxn][Maxn];// 記好 !!
int solve(int left, int right, int l_idx, int r_idx){
    /*
    left: 此段木棍左邊
    right: 此段木棍右邊
    l_idx: 欲使用之切割點的最左 index
    r_idx: 欲使用之切割點的最右 index
    */

    int len = right - left;
    // 全部記熟 !!
    if (l_idx == r_idx){//只有一點
        return len;
    }
    else if (l_idx > r_idx){//沒有切割點
        return 0;
    }
    else if (dp[l_idx][r_idx] != INF){//已計算過
        return dp[l_idx][r_idx];
    }

    for (int i = l_idx; i <= r_idx; i++){// 範圍記好，然後"<=" !!
        dp[l_idx][r_idx] = min(dp[l_idx][r_idx], solve(left, cut[i], l_idx, i - 1) + solve(cut[i], right, i + 1, r_idx) + len);
        // 注意後面那項!! 要加 len !!
        // 為切完產生的兩段的成本+原長 , ex : 切在50 -> 0~50和50~100的成本
        // 前後兩段範圍注意!!
    }
    return dp[l_idx][r_idx];// 別忘 !!
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int len, n;
    while (cin>>len){
        if(len == 0){
            break;
        }
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> cut[i];
        }

        //INF不要用memset
        for (int i = 0; i < Maxn; i++){
            for (int j = 0; j < Maxn; j++){
                dp[i][j] = INF;
            }
        }
        // 參數記好 , 是len不是len-1!!
        cout << "The minimum cutting is " << solve(0, len, 0, n - 1) << ".\n";
    }

    return 0;
}

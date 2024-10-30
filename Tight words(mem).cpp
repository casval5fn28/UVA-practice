#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    // cnt[i][j] = 長度為i且末位為j,又滿足要求的
    int k, n;
    while (cin >> k >> n){
        double cnt[101][10] = {0};//在這 , 先 101
        for (int i = 0; i <= k; i++){// <= !!!
            cnt[1][i] = 1;
        }
            
        for (int i = 2; i <= n; i++){//1用過了 , 從2 & <= n ,記好 !!!!!!!!!!! ***********
            for (int j = 0; j <= k; j++){// <=k
                for (int t = 0; t <= k; t++){// <=k
                    if (abs(j - t) <= 1){// j-t , <= !!
                        cnt[i][t] += cnt[i - 1][j];// i-1 , += , j ***************** 
                    }
                }
            }            
        }
        double total = 0;// double !!
        for (int i = 0; i <= k; i++){// <=k
            total += cnt[n][i];// cnt[n][i] !!
        }
        cout << fixed << setprecision(5) << (total * 100.0 / pow(k + 1, n)) << '\n';//記好!! k+1個字母選擇 ^ 長度 n
    }

    return 0;
}
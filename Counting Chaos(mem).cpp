// Counting Chaos
// UVa ID: 11309
// 回文時間

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);

    vector<int> chaos;
    for (int i = 0; i <= 23; i++){
        for (int j = 0; j <= 59; j++){
            int n = i * 100 + j;
            int num = 0;//記好 !!
            int tmp = n;
            while (tmp > 0){//化成數字 , 方便判斷
                num = num * 10 + tmp % 10;//記好 !!
                tmp /= 10;// 先%再/ , 記好 !!
            }
            if (n == num){ // 有回文 , 記得對到num !!
                chaos.push_back(i * 60 + j);// 丟時間 , 注意 !!
            }
        }
    }
        

    int n;
    string time;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> time;// 不要getline , 會RE
        int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));// idx 0 開始兩位 和 idx 3 開始兩位 , 換算分鐘
        // upper_bound 語法注意 !!
        int k = upper_bound(chaos.begin(), chaos.end(), t) - chaos.begin();//找對的idx , 整句記好 !!
        if (k == chaos.size()){
            k = 0;// 不要忘 !!******************
        } 
        t = chaos[k];
        int hh = t / 60;// 用 t !!
        int mm = t % 60;
        cout << setw(2) << setfill('0') << hh << ':';//記得填滿
        cout << setw(2) << setfill('0') << mm << '\n';//記得填滿
    }

    return 0;
}
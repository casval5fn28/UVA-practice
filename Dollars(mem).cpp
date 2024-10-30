// Dollars
// UVa ID: 147
// PDF 格式的試題描述和 UVa 網頁上的試題描述有出入，主是上限提高到 300 美元。輸出格式亦有改變。

#include <bits/stdc++.h>
#define ll long long int // 要 long long !!
#define Maxn 10001// 這數量可以
using namespace std;

ll way[Maxn] = { 0 }; //記好 !!!

void init(){
    ll coins[11] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };//種類記好 , 尤其最後兩個!!
    way[0] = 1;// 要記得，所以後面從1
    for (int i = 0; i < 11; i++){//11種幣值
        for (int j = 1; j < Maxn; j++){//從 1 開始 !!
            if (j - coins[i] >= 0){//別忘 !!
                way[j] += way[j - coins[i]];
            }   
        }        
    }     
}

int main(){
    init();
    
    string line;
    while (cin >> line){
        string total = line;
        line.erase(line.find('.'), 1);//略過小數點，比較好換算
        istringstream iss(line);// istringstream 和 iss() !!
        
        ll money;
        iss >> money;
        
        if (money == 0)
            break;
        
        //題目輸出要求 , 記好 !!
        cout << fixed << setprecision(2) << setw(6) << right << total;//記得fixed & setprecision(2) & right記得 !!
        cout << setw(17) << right << way[money / 5] << "\n";// right記得 !! 然後coin取1/5所以這裡除以5
    }
    
	return 0;
}
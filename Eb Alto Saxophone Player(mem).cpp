//Eb Alto Saxophone Player	
//uva 10415
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;
//重複的鍵不連按
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);

    map<char, vector<int>> press = {
        {'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
        {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
        {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}
    };
    
    string ipt;
    int cases;
    getline(cin, ipt);// 用 getline !!
    //cin>>cases; 
    stringstream ss(ipt);
    ss >> cases; //轉成數字, 不用string轉會多一行 !!!!!!!

    for (int c = 0; c < cases; c++){
        string line;
        getline(cin, line);
        vector<int> cnt(10,0);// 別忘 !!
        if (line.size() != 0){//第一行，注意!!
            for (int i = 0; i < 10; i++){//注意到10 !!***
                cnt[i] += press[line[0]][i];// line[0] !!
            }
                
        }
        for (int i = 1; i < line.size(); i++){//後面幾個音 , i start from '1' !!
            for (int j = 0; j < 10; j++){
                if (press[line[i]][j] && !press[line[i - 1]][j]){// 記好 !!
                    cnt[j]++;//是j !!
                }   
            }
                
        }
        for(int i = 0; i < 9; i++){//注意只到9
            cout << cnt[i] << " ";
        }
        cout << cnt[9] << '\n';//最後一個換行
    }

    return 0;
}


/*
題解:
本題只要計算每個音符會用到的按鍵
並且考慮到如果前一次有按的話此次就不能計入

作法:
將所有音符以及其按鍵包成 string array
包含音符及其按鍵

接著另外設立 current 以及 next
跑一層迴圈 比對前一次和當下那次是否有重複用到的按鍵
與前一次沒有重複才能把 count++
*/
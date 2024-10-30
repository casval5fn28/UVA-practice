//Power Strings	
#include <iostream>
#include <vector>
#include <string>
#define ll long long
//字段重複量
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    string line;
    while (getline(cin, line)){
        if (line == "."){
            break;
        }
        bool repeated = false;
        for (int i = 1; i < line.length(); i++){//注意從1
            if (line.length() % i == 0){//記好!!!!1 *************
                bool same = true;
                for (int j = i; j < line.length(); j += i){//注意從i, j+=i !
                    for (int k = 0; k < i; k++)//注意0~i-1範圍
                        if (line[k] != line[k + j]){
                            same = false;
                            break;
                        }
                    if (!same){//這裡記得!
                        break;
                    }
                }
                if (same){//記好位置!!
                    repeated = true;
                    cout << line.length() / i << '\n';//記得/i !!
                    break;//都要記得break !
                }
            }
        }
        if (!repeated){//無重複長度>=2之字串
            cout << 1 << '\n';
        }
    }
    return 0;
}
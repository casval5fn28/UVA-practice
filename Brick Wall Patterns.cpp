#include <bits/stdc++.h>
//擺放方式有多種
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);

    long long int ways[51] = {1, 2, 3};// 前三個assign好 , 記好 !!********
    
    for (int i = 3; i < 50; i++){//3到50就好**************
        ways[i] = ways[i - 1] + ways[i - 2];// 記好 !!
    } 
    
    int n;
    while (cin >> n) {// 記好 !!
        if(n == 0){
            break;
        }
        cout << ways[n - 1] << '\n';// "n-1" ***************
    }
    
    return 0;
}
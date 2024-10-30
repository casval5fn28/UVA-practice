#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ll long long // int也能過
using namespace std;
//text中字對應的錢數總和
int main(){
    ll total;
    map<string,ll> table;

    ll m,n,usd;
    string word;
    cin>>m>>n;
    for(int i = 0 ; i < m ; i++){
        cin>>word>>usd;
        table[word] = usd;
    }
    string line;
    for(int i = 0 ; i < n ; i++){
        total = 0;
        while(cin>>line&&line!="."){//記好!!
            total += table[line];//記好!!
        }
        cout<<total<<"\n";
    }
    return 0;
}

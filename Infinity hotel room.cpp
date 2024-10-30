#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
//級數累加，不準錯
int main(){
    ll group, day, sum, i, res;//一定要 long long 記好!!
    while(cin>>group>>day){
        sum = 0;
        for(i = group ; i<=day ; i++){//記好
            sum += i;
            if(sum >= day){
                res = i;
                break;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
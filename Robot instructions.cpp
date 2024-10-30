#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin>>test;

    for(int j=0 ; j < test ; j++){
        int n,tmp;//別忘!!
        cin >> n;
        int pos = 0;
        int step[105]={0};//別忘!!
        string action;//注意!!

        for(int i=1; i<=n; i++){//注意i從1到n , 不然repeat action會錯個 !!
            cin>>action;
            if (action == "LEFT"){
                step[i] = -1;    
            }
            else if (action == "RIGHT"){
                step[i] = 1;
            } 
            else{
                cin >> action >> tmp;;//記好 !!
                step[i] = step[tmp];
            }
            pos += step[i];
        }
        cout<<pos<<"\n";
    }
    return 0;
}


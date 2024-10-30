// uva 719
// 注意 !!
#include <algorithm>
#include <iostream>
//最小字典序，很煩 
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int cases;
    string s;
    cin >> cases;
    for (int c = 0; c < cases; c++){
        cin >> s;
        int i = 0, j = 1, k, n = s.length();//注意!!
        while (i < n && j < n){
            k = 0;//記得!!
            while (k < n && s[(i + k) % n] == s[(j + k) % n]){//注意!! // 用 ==
                k++;
            } 
            if (k == n){//跑完
                break;
            }
            if (s[(i + k) % n] > s[(j + k) % n]){//注意!! //i不是最小表示 // 用 >
                i = max(j, i + k + 1);// 用i,記好!!
                j = i + 1; // 只有=
            }
            else{//j不是最小表示
                j += k + 1; // 有+=
            } 
        }
        cout << (i + 1) << '\n';//注意是i+1!!
    }
    return 0;
}

//以下較慢但簡單
///Glass Beads	
/*#include<iostream>
#include<string>
#define ll long long

using namespace std;

void comp(string str,int n){

    ll min=0;
    string minstr(str,0,n);//記好!!
    for(ll i=0;i<n;i++){
        string a(str,i,n);//記好!!
        string b(str,i+1,n);//記好!!
        if(a<b && a<minstr){//記好!!
            minstr = a;
            min = i;/////
        }
        else if(a>b && b<minstr) {//記好!!
            minstr=b;
            min=i+1;/////
        }
    }
    cout<<min+1<<"\n";

}


int main(){
    ll n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        comp(s+s,s.length());
    }
    return 0;
}*/

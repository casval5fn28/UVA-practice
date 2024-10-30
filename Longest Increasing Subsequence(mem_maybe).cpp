//Longest Increasing Subsequence
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

ll LIS(vector<ll> vec){
    vector<ll> res;
    // ll pos=0,val=0;
    for(ll i = 0 ; i < vec.size() ; i++){

        vector<ll>::iterator itr = lower_bound(res.begin(),res.end(),vec[i]);//注意(std::)lower_bound,用res,和最後的vec[i]
        if(itr == res.end()){//注意沒'*'和 '=='
            res.push_back(vec[i]);
        }
        else{
            (*itr)=vec[i];//注意(*itr)
        } 
    }
    return res.size();//記好!

}


int main(){

    ll N;
    cin>>N;
    vector<ll> vec;
    ll a;
    while(N--){
        cin>>a;
        vec.push_back(a);
    }
    
    ll ans = LIS(vec);
    cout<<ans<<"\n";
    return 0;
}
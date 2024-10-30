// Urn-ball Probabilities!	
// uva 10169
// 背好 !
#include<iostream>
#include<vector>
#include<iomanip>// for setprecision
#include<cmath>
//甕裡的球，重要
#define ll long long
#define Maxn 1000001
using namespace std;

vector<double> vec(Maxn,0);//數字要一樣 , 要 double
vector<int> digit(Maxn,0);//數字要一樣 , 要 int

void calcu(){
    double q = 1 ,dg = 0;//記好!!
    for(ll i = 1 ; i < Maxn ; i++){// 從 1 !! , 用 long long !!!

        double tmp = ( 1.0 / ( i * (i + 1)));//red // 1.0 !!!
        q *= ( 1 - tmp );//no both red
        vec[i] = 1 - q;//at least one both red // = p

        dg += log10( 1/tmp ); // "+=" , 記好 !!!
        digit[i] = (int)( dg - fmod(dg , 1));// fmod : 浮點餘數 ex : fmod(5.3,2) = 1.3 //不要忘記(int) !!!
    }
}

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);
    calcu();//先建表
    ll n;
    while(cin>>n){
        cout<<fixed<<setprecision(6)<<vec[n]<<" "<<digit[n]<<"\n";//記好!!
    }
    return 0;
}
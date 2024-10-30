//uva 10193
#include <iostream>
#include <algorithm>// __gcd
#include <string>
// 最大公因數
using namespace std;

int str_to_int(string s1, string s2){//注意是int
    int n1=0, n2=0;//記得歸0
    for(int i = 0 ; i < s1.size(); i++){//二進位，所以*2
        n1 = (2*n1) + (s1[i]-'0');
    }
    for(int i = 0 ; i < s2.size(); i++){//二進位，所以*2
        n2 = (2*n2) + (s2[i]-'0');
    }
    return __gcd(n1,n2);// 別忘 !
}

int main(){
    int num,test=1;
    cin>>num;
    while(num--){
        string s1,s2;
        cin>>s1>>s2;

        if(str_to_int(s1, s2) != 1){
            cout<<"Pair #"<<test++ <<": All you need is love!"<<"\n";
        }
        else{
            cout<<"Pair #"<<test++ <<": Love is not all you need!"<<"\n";
        }
    }
    return 0;
}

// All in All
// uva 10340
#include<iostream>
#include<string>
//前字串是否為後字串的子字串
using namespace std;

int main(){
    string s1,s2;
    int n,ct;

    while(cin>>s1>>s2){//這邊用cin !!
        n = s1.size();
        ct = 0;
        
        for(int i = 0 ; i < s2.size() && ct < n ; i++){//記得 ct < n
            if(s2[i]==s1[ct]){
                ct++;
            } 
        }

        if(ct==n){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }

    return 0;
}


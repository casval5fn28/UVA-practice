#include<iostream>
#include<algorithm>
// find d = a+b+c
using namespace std;

int main(){
    int data[1000];//記好
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
            
        for(int i=0; i<n; i++){
            cin >> data[i];
        }
        sort(data,data+n);//記好!!!!!!!!!!!!!!!!!!!!!
        
        bool found = false;//記好
        int a,b,c,d;
        int ans=0;
        for(d = n-1; d>=0 && !found; d--){//這段注意，最後面所以從第n-1個
            for(a = 0; a < n && !found; a++){//這段注意(a=0)
                if(a==d){
                    continue;
                }    
                for(b = a+1; b < n && !found; b++){//這段注意(b=a+1)
                    if(b==d){
                        continue;
                    } 
                    for(c = b+1; c < n && !found; c++){//這段注意(c=b+1)
                        if(c==d){
                            continue;
                        }   
                        if(data[a] + data[b] + data[c] == data[d]){//這段注意
                            found = true;
                            ans = data[d];
                            //cout << "found " << data[d] <<"\n";
                        }
                    }
                }
            }
        }

        if(found){
            cout << ans <<"\n";
        }   
        else{
            cout << "no solution" <<"\n";
        }     
    }
    return 0;
}
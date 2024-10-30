#include<iostream>
#include<vector>
#define ll long long
#define MAXN 10050 // 數字重要 !!
using namespace std;
vector<ll> primes;
bool visited[MAXN];

void PrimeGenerator(){
    primes.push_back(2);
	for(int i = 3 ; i <= MAXN ; i += 2){
        if(!visited[i]){
            primes.push_back(i);
            for(int j = i*2 ; j <= MAXN ; j += i){//記好!
                visited[j]=true;
            }
        }
    }
}

int main (){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    PrimeGenerator();
    ll N,sum,cnt;
    while(cin >> N){// &&N : 0 then stop
        if(N==0){
            break;
        }
        cnt = 0;//記好 !!
        for (ll i = 0 ; primes[i] <= N ; i++){//記好 !!
            sum = primes[i];
            for (ll j = i+1 ; sum < N ; j++){//記好 !!**********
                sum+=primes[j];
            }
            if (sum == N){
                cnt++;
            }

        }
        cout << cnt << "\n";
    }
    return 0;
}


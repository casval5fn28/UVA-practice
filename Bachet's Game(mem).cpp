#include<iostream>
#include<cstring>
//背包
using namespace std;
const int Maxn = 1e6+5;//用const !!
bool win[Maxn];
int moves[11];// m<=10

int main(){
	int n;
	while(cin>>n){
		memset(win,false,sizeof(win));//每輪重置 , 別忘
		int m;
		cin>>m;
		for(int i = 0 ; i < m ; i ++){
			cin >> moves[i];
		}

		for(int j=1 ; j<=n ; j++ ){// j = number of left stones , <= n !!
			for(int i = 0 ; i < m ; i++){//變數記好 // <= m !!!
				if(j-moves[i] >= 0 && win[j-moves[i]]==false){// the latter : Ollie(j-moves[i]) lose
					win[j] = true;// j !!
				}
			}
		}
		if(win[n]==true){
			cout<<"Stan wins\n";
		}
		else{
			cout<<"Ollie wins\n";
		}
	}
	return 0;
}
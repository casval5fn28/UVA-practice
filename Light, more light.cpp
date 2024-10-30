#include <iostream>
#include <cmath>
#define ll long long int
//確認該數字是否為完全平方數
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	ll test;
	while(cin>>test){
		if(test==0){
			break;
		}
		ll root = sqrt(test);
		if(root*root == test){
			cout<<"yes"<<"\n";
		}
		else{
			cout<<"no"<<"\n";
		}
	}
	return 0;
}

/*
本題是由 1 到 n
每次將此數的倍數做 switch
最後要是亮的
而燈泡一開始是暗的
所以要被 switch 過 奇數次
這就表示這個數字要有奇數個因數
而擁有奇數個因數的數字
就只有完全平方數
因此只要確認該數字是否為完全平方數就能會亮

作法:
吃進數字後
用 sqrt(n)相乘
若是完全平方數 則 n 會等於 sqrt(n) 的平方
*/
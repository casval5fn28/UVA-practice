// UVa10090 Marbles
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define ll long long int
using namespace std;

ll n, c1, n1, c2, n2;

void gcd(ll a, ll b, ll& d, ll& x, ll& y){//後面三個會要改runcase()處的值 , 要加"&" !!!
//記好 !!
    if(b == 0) {
		x = 1;
		y = 0;
        d = a;
    }
    else{
        gcd(b, a%b, d, y, x);// y 然後 x !!
        y -= x * (a/b);
    }
}

void runcase(){    
    // 先求方程 n1 * x + n2 * y = gcd(n1, n2) 的整數解
    ll g, x, y;
    gcd(n1, n2, g, x, y); // 參數記好 !!!!!!!
    if( n % g != 0 ) { // 沒有gcd
        cout<<"failed"<<"\n";
        return;// retrun 而已
    }
    
    x *= n/g;
    y *= n/g;
    // 方程的所有整數解都可以寫成 x + k * n2/g, y - k * n1/g, 接下來求出讓這兩個數都 >=0 的k的範圍
    // x + k*n2/g >= 0 -> k >= - x / (n2/g)
    // y - k*n1/g >= 0 -> k <= y / (n1/g)
	// ceil() 函數返回大於或等於給定參數的最小可能整數值
	//記好 !!
    ll minK = ceil(- ((double)x) / (n2 / g));//多負號 , x&n2 !!
	ll maxK = floor(((double)y) / (n1 / g));// y&n1 !!
    if(minK > maxK){
        cout<<"failed"<<"\n";
        return;// retrun 而已
    }
    
    // 若 c1 * n2 <= c2 * n1，此種情況下 x 越大花費越少，則 k 取上限。
	// 反之 k 取下限，x 越小花費越少。等於的情況可放到任意一個情況中，因為所產生費用相當。
	

    /////////////////////////////////////////////////////
	//記好 !!!!!!!!!!!*****************
	if (c1 * n2 <= c2 * n1)  {
        // n/g和mxxK互乘 !! 再加減x/y  
        x = n2 / g * maxK + x;  
        y = y - n1 / g * maxK;  
    }  
    else  {  
        x = n2 / g * minK + x;  
        y = y - n1 / g * minK;  
    }
    /////////////////////////////////////////////////////  
      
    cout << x << " " << y << "\n";  
}

int main() {
    while(cin>>n>>c1>>n1>>c2>>n2){   
        if(n == 0){
			break;
		}
        runcase();
    }
    return 0;
}
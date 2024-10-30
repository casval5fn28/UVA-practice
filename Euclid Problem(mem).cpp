#include <bits/stdc++.h>
using namespace std;

int x,y,d;

// ax + by = d
// store x, y, and d as global variables
void euclid(int a, int b) {

    if (b == 0) { //整段記好 !!!!!
        x = 1;
        y = 0;
        d = a;
        return;// *********
    } // base case

    euclid(b, a % b); // similar as the original gcd
    int x1 = y;// 記好!!
    int y1 = x - (a / b) * y;// 記好!!
    x = x1;
    y = y1;
}

int main() {
    //不要cin.tie
    int a,b;
    while(cin>>a>>b) {
        euclid(a,b);
        cout << x << " " << y << " " << d << "\n";
    }
}
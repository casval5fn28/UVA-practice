#include <iostream>
#include <vector>
using namespace std;
// 座標轉換
// 這兩個東西記得 !!
const int Maxn = 1e6;
const int layer = 200;
vector<pair<int, int>> coords;

void generate_coords() {
    coords.assign(Maxn, {-1, -1});//背語法
    coords[1] = {0, 0};

    int x = 0, y = 0, idx = 1;// idx = 1 記好 !! *********
    for (int l = 0; l < layer; l++) {// there're 6 more points for each layer // use 'l' !!
        x++;//重要!!
        for (int i = 0; i <= l; i++) coords[++idx] = {--x, ++y};// i <= l !!!(一定要'=') //--x重要 , 迴圈內要++/--在前
        for (int i = 0; i <= l; i++) coords[++idx] = {--x,   y};
        for (int i = 0; i <= l; i++) coords[++idx] = {  x, --y};
        for (int i = 0; i <= l; i++) coords[++idx] = {++x, --y};
        for (int i = 0; i <= l; i++) coords[++idx] = {++x,   y};
        for (int i = 0; i <= l; i++) coords[++idx] = {  x, ++y};
    }
}

int main() {
    //ios_base::sync_with_stdio(0);

    int n;
    generate_coords();
    while (cin >> n) {
        cout << coords[n].first << " " << coords[n].second <<"\n";
    }
    return 0;
}
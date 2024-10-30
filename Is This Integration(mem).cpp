// [解題方法]
// 設斜線部分的面積為 X，打點部分的面積為 Y，網格部分的面積為 Z，則有以下方程：
//
// X + 3 * Y / 4 + Z / 2 = pi * a * a / 4
// X + Y + Z = a * a
//
// 要解方程，必須還有一個獨立方程，這個可以由計算左下角和右下角兩個四分之一圓重疊部分的面積來得到，
// 這個重疊的面積很容易計算，仔細觀察一下圖就可以得到。
//
// X + Y / 2 + Z / 4 = pi * a * a / 3 - sqrt(3) * a * a / 4
//
// 聯立三個方程可得：
//
// X = a * a * (1 - sqrt(3) + pi / 3)
// Y = a * a * (2 * sqrt(3) - 4 + pi / 3)
// Z = a * a * (4 - sqrt(3) - 2 * pi / 3)

#include <bits/stdc++.h>

using namespace std;

int main(){
	double a, x, y, z; // double !
    double pi = M_PI;// 圓周率，背
	
	while (cin >> a){
        //三公式記好!!
		x = a * a * (1 - sqrt(3) + pi / 3);//先1
		y = a * a * (2 * sqrt(3) - 4 + pi / 3);//先*2再-4
		z = a * a * (4 - sqrt(3) - 2 * pi / 3);//先4再-2*pi/3
		
		printf( "%.3lf %.3lf %.3lf\n", x, y, z );//輸出控制用 , .3lf記好 !
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
//最大正方，很煩
int main(){
    int test;
    int height, width, center_num;
    int row, column; // location of square
    int max_sidehalf;

    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> height >> width >> center_num;
        cout << height << " " << width << " " << center_num << "\n";
        
        string square[height];//是string !!//不用常數值height沒差//記得有這個 !!
        for (int m = 0; m < height; m++){
            cin >> square[m];
        }

        for (int j = 0; j < center_num; j++){
            cin >> row >> column;
            max_sidehalf = 0; // the length between center and side

            char center = square[row][column]; //別忘 !!

            // 這3句記好 !!!!!
            int max_height = min(row, height-row-1);
            int max_width = min(column, width-column-1);
            int max_tmp_half = min(max_height, max_width);

            // check if there is x length of a side of square, x = k * 2 + 1
            bool isSquare;// 記好 !!
            for (int k = 1; k <= max_tmp_half; k++){//僅1點的不列入，所以用1~<=max_tmp_half !!!
                isSquare = true; // 在這 !!
                for (int m = row-k; m <= row+k; m++){//以中心往兩側多k
                    for (int n = column-k; n <= column+k; n++){//道理同前
                        if (square[m][n] != center){
                            isSquare = false;
                            break;// 記好 !!
                        }
                    }
                }
                
                if (isSquare){// 在k回圈內 !!
                    max_sidehalf++;
                }
                else {
                    break;// 記好 !!
                }
            }
            cout << max_sidehalf*2+1 << "\n";
        }
    }
    return 0;
}
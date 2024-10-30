#include <iostream>
#include <string>
//骰子旋轉
using namespace std;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); tle is added ??
    int top, bottom, east, west, north, south, tmp;
    int turn;
    string input;

    while (cin>>turn){// stop if input = 0
        top = 1; bottom = 6;
        north = 2; south = 5;// 這行注意
        east = 4; west = 3; // 這行注意
        if(turn == 0){
            break;
        }
        while (turn--){
            cin>>input;

            tmp = top;//記得!!

            if (input[0] == 'n'){
                top = south;//記得照順序!!
                south = bottom;
                bottom = north;
                north = tmp;
            }
            else if (input[0] == 'e'){
                top = west;
                west = bottom;
                bottom = east;
                east = tmp;
            }
            else if (input[0] == 's'){
                top = north;
                north = bottom;
                bottom = south;
                south = tmp;
            }
            else{
                top = east;
                east = bottom;
                bottom = west;
                west = tmp;
            }
        }
        cout<<top<<"\n";//在這 , 用 top !!
    }
    return 0;
}

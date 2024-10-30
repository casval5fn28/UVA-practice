//Cola
#include <iostream>
#include <vector>
using namespace std;
//可樂題
int main(){
    int n;
    int coke_sum = 0, coke_empty = 0;//注意
    while(cin >> n){
        coke_sum = n;
        coke_empty = n;
        while(coke_empty >= 3){//empty !!
            coke_sum += (coke_empty / 3);
            coke_empty = (coke_empty / 3) + (coke_empty % 3);//注意沒有+=
        }    
        int ans = 0;
        if(coke_empty == 2 ){
            ans = coke_sum + 1;//差一瓶可以補1
        }
        else{
            ans = coke_sum;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
題解:
這題是經典的可樂題
三個空瓶換一瓶新可樂
可以借一瓶空瓶來湊換新可樂

作法:
一個迴圈不斷更新空瓶數量
如果大於 3 就一直將答案加上 empty/3
然後空瓶數量要更新成原本的 mod 3 再加上 原先的 / 3

最後如果剩餘的空瓶數量等於 2
則可以再借一空瓶 將答案 + 1


*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int testcase ;
    cin>>testcase;

    string line;
    getline(cin, line);//有空行別忘!!**************
    for (int c = 0; c < testcase; c++){
        getline(cin, line);//有空行別忘!!**************

        double x1, y1, x2, y2;//用double !!
        double trail = 0.0;//用double !!
        while (getline(cin, line), line.size() > 0){//後半記得 !!
            istringstream iss(line);// istringstream iss(x) !!
            iss >> x1 >> y1 >> x2 >> y2;
            trail += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//路長
        }
        
        trail /= 1000; //換算成公里
        double hr = trail * 2 / 20; //雙向距離，時速 20km //數字記好 !!
        double time = hr * 60.0; //換算成分鐘 , 小數點 !!
        
        int minutes = round(time);//記得 round 然後轉 int !!
        int hours = minutes / 60;
        minutes %= 60;
        
        //輸出記好 !!
        if (c > 0){ //不要忘記 !!!!! *******
            cout << "\n";
        }
        cout << hours << ":";
        if (minutes < 10){
            cout << '0';//超機掰
        }
        cout << minutes << "\n";
    }
    
    return 0;
}
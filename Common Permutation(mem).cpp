// Steven Kester Yuwono - UVa 10252
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 123// define 沒 ';'...
using namespace std;
//找字串共同的字元集
int freq1[MAX];
int freq2[MAX];

int main() {
	string line1,line2;
	while(getline(cin,line1),getline(cin,line2)) {//這題不能連續cin !!
		memset(freq1,0,sizeof(freq1));
		memset(freq2,0,sizeof(freq2));
		for(int i = 0 ; i < line1.size() ; i++){
			freq1[line1[i]]++;
		}
		for(int i = 0 ; i < line2.size() ; i++){
			freq2[line2[i]]++;
		}

		for(int i = 'a'; i <= 'z' ; i++){//注意<=
		//下面注意 !!!
			int maxChar = min(freq1[i],freq2[i]);//沒有的會是0，被後面迴圈排除
			for(int j = 0 ; j < maxChar ; j++){//注意
				cout << (char)i;// 用"i"注意!!
			}
		}
		cout << "\n";
	}
	return 0;
}
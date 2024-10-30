/**
	UVa 10126 - Zipf's Law
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.095s C++
	O(nlogn) time
*/
//給定一篇文章，定義一個字為連續的字元，且不記大小寫，問文章中出現次數是 n 的有哪些字
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    string buf, word;// 記好 !!
    int n;
    bool found, f=false;// 記好"f" !!

	while( cin >> n ){//這迴圈要留...，有很多組task
		if( f ){
            cout << "\n";
        }
		f = true;
		map<string, int> mp;// 格式記好 !!
		map<string, int>::iterator it;
		while( cin >> buf ){
			transform( buf.begin(), buf.end(), buf.begin(), ::tolower );// 記好 !!
			if( buf=="endoftext" ){
                break;
            }
			for(int i = 0; i < buf.size(); i++ ){
				if( islower( buf[i] ) ){
					//word.clear();// 記好 !!
					word = "";
					while( i < buf.length() && islower(buf[i]) ){// 記好 !! *****
						//word.push_back( buf[i++] );
						word.insert(word.end(), buf[i++]);
					}
					mp[word]++;// 別忘 !!
				}
			}
		}
		//以下在while外面，記好!!
		found = false;
		for( it=mp.begin(); it!=mp.end(); it++ ){
			if( it->second == n ){// ->second !!
				cout << it->first << "\n";// ->second !! 記好 !!
				found = true;
			}
		}
		if( !found ){
            cout << "There is no such word." << "\n";
        }
	}

    return 0;
}
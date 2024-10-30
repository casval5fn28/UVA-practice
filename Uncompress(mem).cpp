#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string buf;
	vector<string> word_list;//別忘!!
	while (getline(cin, buf) && buf[0] != '0') {//記好 !!
		string s;
		for (int i = 0; buf[i]; i++) {// buf[i]記好!!!
			if (isalpha(buf[i])) {// letter
				s = "";
				while (isalpha(buf[i])){//form a word
                    // buf[i++] ***************
					s.insert(s.end(), buf[i++]);// i++ !!
				}
				word_list.push_back(s);
				i --;// go on a new word , start from head again //記好 !!
				cout << s;//記好 !!
			}
			else if (isdigit(buf[i])) {// number
				int value = 0;
				while (isdigit(buf[i])){
					// buf[i++] ***************
                    value = value * 10 + (buf[i++] - '0');// make thing in '()' be int // i++ !!
				}
				//整段記好 !!!!
				s = word_list[word_list.size() - value];// count value from the most previous word
				word_list.erase(word_list.end() - value);// delete the original index of the repeated word , erase only use 'end()' for iterator
	        	word_list.push_back(s);// add to be the 'most previous word' //別忘 !!!
	        	i --;// go on a new word , start from head again
				cout << s;//記好 !!
			}
			else {// symbol
                cout << buf[i];
			}
		}
		cout<<"\n";// it changes lines = _ = //別忘!!!**************
	}
    return 0;
}
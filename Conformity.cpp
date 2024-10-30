#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//最多人選的課程組合數
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	while(cin>>n){
		if(n==0){
			break;
		}
		map< vector<int>, int > frosh;// 記好 !!
		vector<int> course(5); // 記好 !!
		
		for(int i = 0; i < n ; i++){
			for(int j = 0 ; j < 5 ; j++){
				cin>>course[j];
			}
			sort(course.begin(),course.end());
			if(frosh.count(course) == 1){//注意語法!!*****
				frosh[course]++;
			}
			else{
				frosh[course]=1;
			}
		}

		int amount = 0;
		map<vector<int>,int>::iterator it;
		// 語法注意 !!
		for(it = frosh.begin(); it != frosh.end(); it++){
			if(it->second > amount){
				amount = it->second;
			}
		}

		int cnt = 0;
		for(it = frosh.begin(); it != frosh.end(); it++){
			if(it->second == amount){
				cnt ++;
			}
		}
		amount*=cnt;
		cout<<amount<<"\n";
		//frosh.clear();// 別忘
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<algorithm>
#define Maxn 105
using namespace std;
//比分，很煩
struct Team{
  	bool join;
  	int num;
  	int penalty;
  	int problem;
  	int error[10];//記好 !
};// 有;
bool cmp( Team a, Team b ){
  	if( a.problem > b.problem ) return true;
  	if( a.problem < b.problem ) return false;
  	if( a.penalty < b.penalty ) return true;
  	if( a.penalty > b.penalty ) return false;
  	if( a.num < b.num ) return true;
  	return false;//記得!!
}

int main(){
	int testcase;
	// 整段注意 !!
	string entry;
	
	Team teams[Maxn];
	int contestant, problem, time;
	char L;

	while(cin>>testcase){
		getchar();//注意
		getchar();
		for( int i = 0 ; i < testcase ; i++ ){//括號注意!!!
			if( i ) {//注意!
				cout<<"\n";
				//printf( "\n" );
			}
			for( int j = 0 ; j < Maxn ; j++ ){
				teams[j].join = 0;
				teams[j].num = j;
				teams[j].penalty = 0;
				teams[j].problem = 0;
				memset( teams[j].error, 0, sizeof(teams[j].error) );//記得
			}
			while( getline( cin, entry ) && entry != "" ){// 記好 !!
				stringstream ss;
				ss.str(entry); // 注意寫法 str() !!
				ss >> contestant >> problem >> time >> L;// 注意寫法 !!

				teams[contestant].join = true;
				if( teams[contestant].error[problem] == -1 ){// -1 !!
					continue;
				}
				if( L == 'C' ){//注意!! //順序要一樣
					teams[contestant].penalty += time+teams[contestant].error[problem]*20;
					teams[contestant].problem++;
					teams[contestant].error[problem] = -1;//標為正確
				}
				else if( L == 'I' ){
					teams[contestant].error[problem]++;
				}
			} 
			sort( teams, teams+Maxn, cmp );// 別忘 !!
			for( int j = 0 ; j < Maxn ; j++ ){
				if( teams[j].join ){
					cout<<teams[j].num<<" "<<teams[j].problem<<" "<<teams[j].penalty<<"\n";
				}
			}		
		}
	}
	return 0;
}
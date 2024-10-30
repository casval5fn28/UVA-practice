//uva 10007	
#include <iostream>
//卡特蘭樹，給我背起來
 
using namespace std;
 
int C[305][2005] = {0};//一定要放這!!
 
int main(){
	C[1][0] = 1; // 記好 !!
	for (int i = 2 ; i < 301 ; i++) {//特別注意!! , i 從 2
		for (int j = 0 ; j < 2000 ; j++){//0~1999
			C[i][j] += C[i-1][j]*(4*i-2);
		}
		for (int j = 0 ; j < 2000 ; j++) {//0~1999
			C[i][j+1] += C[i][j]/10;
			C[i][j] %= 10;
		}
		for (int j = 1999 ; j >= 0 ; j--) {//1999~0  *****
			C[i][j-1] += C[i][j]%(i+1)*10;//特別注意 , 先%再*!!
			C[i][j] /= (i+1);//特別注意!!
		}
		///////////
		for (int j = 0 ; j < 2000 ; j++){//0~1999
			C[i][j] *= i;//注意!!
		}
		for (int j = 0 ; j < 2000 ; j++) {//0~1999
			C[i][j+1] += C[i][j]/10;
			C[i][j] %= 10;
		}
	}
		
	int n;
	while (cin >> n) {//注意 !!!
		if(n == 0){
			break;
		}
		int end = 1999;//注意 !!!
		while (!C[n][end]){//注意 !!!
			end--;
		}
		while (end >= 0){//注意 !!!
			cout<<C[n][end --];//注意記好 !!! // "end--"
		}
		cout<<"\n";
	}
	return 0;
}
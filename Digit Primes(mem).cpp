//UVa Problem-10533(Digit Primes)
//Accepted
//Running time: 0.324 sec
#include <iostream>
#define Maxn 1000000
//找兩數間符合primeC = primeA + primeB的
using namespace std;

bool visited[Maxn];
int primes[Maxn],total[Maxn];//total[]=符合條件之質數量 , 別忘 !

void get_prime(){
	primes[2] = 1;//別忘
	for(int i = 3 ; i <= Maxn ; i+=2){//注意!!
		if(!visited[i]){
			primes[i] = 1;//這裡記好 !!
			for(int j = i*2 ; j <=Maxn ; j+=i){//這裡記好 !!
				visited[j] = true;
			}
		}
	}
}

//bool visited[MAXN];
//int primek[MAXN],val[MAXN];//val[]=符合條件之質數量


int main(){
	///先製表，不然tle
	get_prime();
	int testcase, val_1, val_2=0, tmp, ct=0;//記得要=0的
	//cin>>testcase;
	// 這題用scanf和printf比較快
	scanf("%d", &testcase);//不要忘記%d &val !!!
	for(int i = 1 ; i <= Maxn ; i++){//一定要從 1 ~ <= Maxn !!!
		val_1 = 0;// 每次重製 !!
		tmp = i;//記好!
		while(tmp != 0){//記好!
			val_1 += tmp%10;
			tmp /= 10;
		}
		if(primes[i] && primes[val_1]){//記好!
			val_2 ++;
		}
		total[ct] = val_2;//記好!
		ct++;
	}

	while(testcase--){
		scanf("%d %d",&val_1, &val_2);
		printf("%d\n",(total[val_2-1]-total[val_1-2]));//記好 !!
	}
	return 0;
}
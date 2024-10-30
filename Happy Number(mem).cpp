//uva 10591
#include <iostream>

using namespace std;
//拆到最後是1或7
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	int n;//the number of the test
	cin>>n;

	for(int i = 0 ; i < n ; i++){//i+1 is the number of case
		//記好 !! ***********
		int input = 0;//store the input;
		int tmp = 0;//store the input temporarily //記得!!
		int sum = 0;//the sum of square of the digits
		int remainder = 0;// the digit of input;

		cin>>input;//start input
		tmp = input;//store the input  //記得!!
		while(1){//start finding the happy number // 注意 !!!!!!

			if(input < 10){//if input < 10, then we find the answer
				sum = input; // 別忘 !!!!!
				break;//break the loop
			}
			while(input != 0){//start comput the sum of the digits

				remainder = input % 10;
				sum += (remainder*remainder); // 記好!!
				input /= 10;
			}
			//先用input !!
			input = sum;//store the sum in the input to start the next loop // 記好!!
			sum = 0;//clear the sum // 記好!!
		}

		if(sum == 1 || sum == 7){// 記好!!用 sum !!
            //the solution < 10 is 1 or 7
            cout<<"Case #"<<i+1<<": "<<tmp<<" is a Happy number."<<"\n";
			//printf("Case #%d: %d is a Happy number.\n", i+1, tmp);
        }
		else{
            cout<<"Case #"<<i+1<<": "<<tmp<<" is an Unhappy number."<<"\n";
            //printf("Case #%d: %d is an Unhappy number.\n", i+1, tmp);
        }
			
	}
	return 0;
}
// UVa 10179 - Irreducable Basic Fractions.cpp
// Direct application of Euler’s Phi function
// C++ program to calculate Euler's Totient Function
// using Euler's product formula

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int eulerPhi(int n){
	//整段記好 !!!!!!!!!!!!!

	double result = n;   // Initialize result as n , 記好 !!
	//int sqrtN = int(sqrt((double)n));
	// Consider all prime factors of n and for every prime
	// factor p, multiply result with (1 - 1/p)
	int p;//位置注意 !!
	// p * p <= n is almost 3 times faster than p <= sqrtN
	for (p = 2; p * p <= n; p++){ // 範圍注意 !!!
		// Check if p is a prime factor.
		if (n % p == 0){
			// If yes, then update n and result
			while (n % p == 0){
				n /= p;
			}		
			result *= (1 - (1 / (double)p));//位置注意 !!//用 p , 記好 !!
		}
	}

	// If n has a prime factor greater than sqrt(n)
	// (There can be at-most one such prime factor)
	if (n > 1){
		result *= (1 - (1 / (double)n));//用 n , 記好 !!
	}
		
	return (int)result;// 記好 !!
}

// Driver program to test above function
int main(){
	int n;
	while (cin>>n) {
		if (n == 0){
			break;
		}
			
		cout << eulerPhi(n) << "\n";
	}
	return 0;
}
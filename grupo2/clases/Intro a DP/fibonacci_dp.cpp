#include <bits/stdc++.h>
using namespace std;

long long dp[100000 + 10];

long long fibo(int n) {
    if(n == 1) 
        return 0;
    if(n == 2) 
        return 1;
        
    if(dp[n] != -1) // ya estaba calculado
        return dp[n];
        
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    //inicializamos el vector dp
    for(int i = 0; i < 100000 + 10; i++)
        dp[i] = -1;
    
    
	int n;//1 <= n <= 1000
	cin >> n;
	cout << fibo(n) << endl;
    return 0;
}

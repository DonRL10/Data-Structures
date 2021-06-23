#include <bits/stdc++.h>
using namespace std;

#define int long long 

void fibo(vector<int> &dp, int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}


signed main(){
    int n;
    cin >> n;

    vector<int> dp(n);
    fibo(dp, n);
    for (auto i: dp){
        cout << i << ' ';
    }
}
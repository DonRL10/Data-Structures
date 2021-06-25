#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n + 1);

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }

    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    cout << dp[n - 1];


}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie();

    solve();

}

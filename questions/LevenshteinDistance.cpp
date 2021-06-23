#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string a, b;
    cin >> a >> b;

    int dp[a.size() + 1][b.size() + 1]; // d[x][y] = minimum number of edit operaations
    
    dp[0][0] = 0;

    for (int i = 1; i <= a.size(); i++){
        dp[i][0] = dp[i - 1][0] + 1;
    }

    for (int i = 1; i <= b.size(); i++){
        dp[0][i] = dp[0][i - 1] + 1;
    }


    for (int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }

            else {
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            }

        }
    }
    cout << dp[a.size()][b.size()];

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
}

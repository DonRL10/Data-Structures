#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18 + 9;
const int NINF = -1e18 - 9;

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }

    int max_so_far = NINF;
    int curr_max = a[0];

    for (int i = 1; i < n; i++){
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }    

    cout << max_so_far;

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}

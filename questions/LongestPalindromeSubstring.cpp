#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    getline(cin, s);
    cin >> s;
    
    int max_len = 1;
    int j = 0;
    int l, r;
    for (int i = 1; i < s.size(); i++){
        //for even
        l = i - 1;
        r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]){
            if (r - l + 1 > max_len){
                j = l;
                max_len = r - l + 1;
            }
            l--;
            r++;
        }
        //for odd
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]){
            if (r - l + 1 > max_len){
                j = l;
                max_len = r - l + 1;
            }
            l--;
            r++;
        }
    }

    for (int i = j; i <= j + max_len - 1; i++){
        cout << s[i];
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
}

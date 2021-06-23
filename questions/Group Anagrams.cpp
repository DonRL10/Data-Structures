#include <bits/stdc++.h>
using namespace std;


vector<string> a;
unordered_map<string, vector<string>> s;

void solve(vector<string> &a){
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < a.size(); i++){
        string temp(a[i]);

        sort(temp.begin(), temp.end());

        s[temp].push_back(a[i]);
    }

    for (auto i: s){
        vector<string> a(i.second);
        for (int i = 0; i < a.size(); i ++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve(a);

    return 0;

 }
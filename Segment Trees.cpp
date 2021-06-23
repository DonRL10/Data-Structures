#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18 +9; 

int construct(int idx, int l, int h, int arr[], int *seg){

    if (l == h){
        seg[idx] = arr[l];
        return arr[l];
    }

    int mid = l + (h - l) / 2;

    seg[idx] = construct(idx*2 + 1, l, mid, arr, seg) + construct(idx*2 + 2, mid + 1, h, arr, seg);

    return seg[idx];
}

//sum on segment [l, r) from alreadt calculate sums
int range_sum(int idx, int low, int high , int l, int r, int *seg){
    if (low > r || high < l){
        return 0;
    }
    else if (low >= l && high <= r){
        return seg[idx];
    }

    int mid = low + (high - low) / 2;

    int sum = range_sum(2*idx + 1, low, mid, l, r, seg) + range_sum(2*idx + 2, mid + 1, high, l, r, seg);
    return sum;
}

void update(int idx, int k_idx, int low, int high, int dif, int *seg){
    if (k_idx < low || k_idx > high){
        return;
    }

    seg[idx] += dif;
    if (low != high){
        int mid = low + (high - low) / 2;
        update(2*idx + 1, k_idx, low, mid, dif, seg);
        update(2*idx + 2, k_idx, mid + 1, high, dif, seg);
    }

}

int range_min(int idx, int low, int high, int l, int r, int *seg){
    return 0;
}

void solve(){
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        arr[i] = x;
    }





    int h = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, h) - 1;

    int *seg = new int[max_size];

    construct(0, 0, n - 1, arr, seg);




    cout << range_sum(0, 0, n - 1, 1, 4, seg) << '\n';

    for (int i = 0; i < 15; i++){
        cout << seg[i] << ' ';
    }
    cout << '\n';




    int key = 4;
    int diff = key - arr[5];
    arr[5] = key;

    update(0, 5, 0, n - 1, diff, seg);

    for (int i = 0; i < 15; i++){
        cout << seg[i] << ' ';
    }
}  

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
 

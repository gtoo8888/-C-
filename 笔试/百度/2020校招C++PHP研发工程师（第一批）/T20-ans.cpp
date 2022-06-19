#include<bits/stdc++.h>

int dig_weight[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

using namespace std;

int main() {
    int capacity, n_item;
    cin >> capacity >> n_item;
    vector<int> weight(9, 0x3ffffff);
    for (int i = 0; i < n_item; ++i) {
        int dig;
        cin >> dig;
        weight[dig - 1] = dig_weight[dig - 1];
    }
    vector<int> dp(capacity + 1,-0x3ffffff);
    dp[0] = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = weight[i - 1]; j <= capacity; ++j) {
            dp[j] = max(dp[j], dp[j - weight[i - 1]] + 1);
        }
    }
    string ans;
    for (int i = 9, j = capacity; i >= 1; --i) {
        for (int cost = weight[i - 1]; j >= cost && dp[j] == dp[j - cost] + 1; j -= cost) {
            ans += (i + '0');
        }
    }
    cout << ans;
}


// Ì°ÐÄ+dp
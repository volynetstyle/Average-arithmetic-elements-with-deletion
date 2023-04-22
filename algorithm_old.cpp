#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
vector<int> a;

int dfs(int idx, int cur_sum, int cur_count, int removed, vector<vector<vector<int>>>& dp) {
    if (idx == n) {
        if (cur_count > 0 && (double)cur_sum / cur_count == (double)(accumulate(a.begin(), a.end(), 0) - cur_sum) / (n - cur_count)) {
            return removed;
        }
        return 0;
    }
    if (cur_sum > accumulate(a.begin(), a.end(), 0) || cur_count > n) {
        return -1;
    }
    if (dp[idx][cur_sum][cur_count] != -1) {
        return dp[idx][cur_sum][cur_count] + removed;
    }
    int res = dfs(idx + 1, cur_sum + a[idx], cur_count + 1, removed, dp);
    res = max(res, dfs(idx + 1, cur_sum, cur_count, removed + 1, dp));
    dp[idx][cur_sum][cur_count] = res - removed;
    return res;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(accumulate(a.begin(), a.end(), 0) + 1, vector<int>(n + 1, -1)));
    cout << dfs(0, 0, 0, 0, dp) << endl;

    return 0;
}

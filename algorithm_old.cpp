#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <sstream>

using namespace std;

int n;
vector<int> a;
int dp[50][50];

int dfs(int idx, int removed) {

    if (idx == n) {
        return removed;
    }
    if (dp[idx][removed] != -1) {
        return dp[idx][removed];
    }
    else {
        int res = dfs(idx + 1, removed);

        for (int i = idx + 1; i < n; i++) {

            // Вычисляем среднее арифметическое первой половины массива
            double first_half_mean = (double)(accumulate(a.begin() + idx, a.begin() + i, 0)) / (i - idx);

            // Вычисляем среднее арифметическое второй половины массива
            double second_half_mean = (double)(accumulate(a.begin() + i, a.end(), 0)) / (n - (i - idx));

            // Проверяем, равны ли средние арифметические
            if (first_half_mean == second_half_mean) {
                res = max(res, dfs(i + 1, removed + i - idx));
            }

        }
        dp[idx][removed] = res;
        return res;
    }
}

int main() {
    // Считываем входные данные.
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);

    cout << dfs(0, 0) << endl;

    return 0;
}

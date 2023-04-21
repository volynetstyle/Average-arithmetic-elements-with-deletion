#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
vector<int> a;
int max_removed = 0;

void dfs(int idx, int cur_sum, int cur_count, int removed) {
	if (idx == n) {
		if (cur_count > 0 && (double)cur_sum / cur_count == (double)(accumulate(a.begin(), a.end(), 0) - cur_sum) / (n - cur_count)) {
			max_removed = max(max_removed, removed);
		}
		return;
	}
	dfs(idx + 1, cur_sum + a[idx], cur_count + 1, removed); // include current element
	dfs(idx + 1, cur_sum, cur_count, removed + 1); // exclude current element
}

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0, 0);
	cout << max_removed << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    if (n < 1 || n > 50) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    size_t sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (std::abs(arr[i]) > 10000) {
            std::cout << 0 << std::endl;
            return 0;
        }
        sum += arr[i];
    }

    const double Avg = static_cast<double>(sum) / n;
    int start = 0, end = n - 1;
    size_t currSum = sum, currCount = n;
    size_t maxRemoved = 0;
    const double eps = 1e-8;

    while (start <= end) {
        double currAvg = static_cast<double>(currSum) / currCount;

        if (std::abs(currAvg - Avg) < eps) {
            maxRemoved = std::max(maxRemoved, n - currCount);
            currSum -= arr[start++];
            currCount--;
        }
        else {
            if (currAvg < Avg) {
                currSum -= arr[start++];
                currCount--;
            }
            else {
                currSum -= arr[end--];
                currCount--;
            }
        }
    }

    std::cout << maxRemoved << std::endl;

    return 0;
}

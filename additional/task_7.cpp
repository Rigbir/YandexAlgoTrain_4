//
// Created by Marat on 21.09.25.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> v[i][j];
        }
    }

    int count = 0;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] == 1) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                count = std::max(count, dp[i][j]);
            }
        }
    }

    std::cout << count;
}
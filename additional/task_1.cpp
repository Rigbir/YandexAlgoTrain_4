//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>
#include <climits>

int getMin(const std::vector<int>& v, int l, int r) {
    int minElement = INT_MAX;
    for (int i = l; i <= r; ++i) {
        if (v[i] < minElement) {
            minElement = v[i];
        }
    }
    return minElement;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::vector<std::pair<int, int>> requests(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> requests[i].first >> requests[i].second;
    }

    for (int i = 0; i < requests.size(); ++i) {
        int l = requests[i].first;
        int r = requests[i].second;

        int minElement = getMin(v, l, r);

        bool found = false;
        for (int j = l; j <= r; ++j) {
            if (v[j] != minElement) {
                std::cout << v[j] << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "NOT FOUND" << '\n';
        }
    }
}
//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::vector<int> pref(n);
    pref[0] = v[0];
    for (int i = 1; i < v.size(); ++i) {
        pref[i] = pref[i - 1] + v[i];
    }

    std::vector<int> result(n);
    for (int i = 0; i < v.size(); ++i) {
        result[i] = (v[i] * i - pref[i - 1]) + ((pref[n - 1] - pref[i]) - v[i] * (n - i - 1));
    }

    for (auto i : result) {
        std::cout << i << ' ';
    }
}
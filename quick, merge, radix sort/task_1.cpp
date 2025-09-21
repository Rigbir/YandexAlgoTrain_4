//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>

std::pair<int, int> partition(std::vector<int>& v, int x) {
    int lt = 0;
    int i = 0;
    int gt = v.size();

    while (i < gt) {
        if (v[i] < x) {
            std::swap(v[lt], v[i]);
            ++lt;
            ++i;
        } else if (v[i] > x) {
            --gt;
            std::swap(v[i], v[gt]);
        } else {
            ++i;
        }
    }

    return {lt, gt};
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int x;
    std::cin >> x;

    auto [f, s] = partition(v, x);
    std::cout << f << '\n' << (n - f);
}

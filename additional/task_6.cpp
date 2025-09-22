//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>

int main() {
    unsigned long long k, n;
    std::cin >> k >> n;

    unsigned long long result = 0;
    std::vector<unsigned long long> rem(n);

    for (int i = 0; i < n; i++) {
        unsigned long long a;
        std::cin >> a;
        result += (i + 1) * 2 * (a / k);
        rem[i] = a % k;
    }

    int j = n - 1;
    unsigned long long free_space = k;
    int cur = 0;

    while (j >= 0) {
        if (rem[j] == 0) {
            --j;
        } else {
            if (free_space == k)
                cur = j;

            if (rem[j] <= free_space) {
                free_space -= rem[j];
                --j;
            } else {
                rem[j] -= free_space;
                free_space = 0;
            }

            if (free_space == 0) {
                result += (cur + 1) * 2;
                free_space = k;
            }
        }
    }

    if (free_space != k) {
        result += (cur + 1) * 2;
    }

    std::cout << result;
}

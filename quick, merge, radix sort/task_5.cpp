//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void countingSortByDigit(std::vector<std::string>& v, int pos, std::vector<std::string>& temp) {
    std::vector<int> count(10, 0);
    for (auto &s : v) {
        int digit = s[pos] - '0';
        ++count[digit];
    }

    std::vector<int> posArr(10, 0);
    posArr[0] = count[0];
    for (int i = 1; i < 10; ++i) posArr[i] = posArr[i - 1] + count[i];

    for (int i = v.size() - 1; i >= 0; --i) {
        int digit = v[i][pos] - '0';
        temp[posArr[digit] - 1] = v[i];
        --posArr[digit];
    }

    v = temp;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int len = v[0].size();

    std::cout << "Initial array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i];
        if (i != n - 1) std::cout << ", ";
    }
    std::cout << "\n";

    std::vector<std::string> temp(n);
    int phase = 1;

    for (int pos = len - 1; pos >= 0; --pos) {
        std::cout << "**********\nPhase " << phase << "\n";
        for (int d = 0; d < 10; ++d) {
            std::cout << "Bucket " << d << ": ";
            bool first = true;
            for (auto &s : v) {
                if (s[pos] - '0' == d) {
                    if (!first) std::cout << ", ";
                    std::cout << s;
                    first = false;
                }
            }
            if (first) std::cout << "empty";
            std::cout << "\n";
        }

        countingSortByDigit(v, pos, temp);

        ++phase;
    }

    std::cout << "**********\nSorted array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i];
        if (i != n - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

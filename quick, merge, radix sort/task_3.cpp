//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>

template <typename RandomIterator>
void merge(RandomIterator fStart, RandomIterator fEnd,
           RandomIterator sStart, RandomIterator sEnd,
           std::vector<int>& result) {

    while (fStart < fEnd && sStart < sEnd) {
        if (*fStart < *sStart) {
            result.push_back(*fStart++);
        } else {
            result.push_back(*sStart++);
        }
    }

    while (fStart < fEnd) {
        result.push_back(*fStart++);
    }

    while (sStart < sEnd) {
        result.push_back(*sStart++);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v1[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> v2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> v2[i];
    }

    std::vector<int> result;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result);

    for (auto i : result) {
        std::cout << i << ' ';
    }
}
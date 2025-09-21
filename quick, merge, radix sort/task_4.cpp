//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>

template <typename RandomIt>
void merge(RandomIt fStart, RandomIt fEnd,
           RandomIt sStart, RandomIt sEnd,
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

template <typename RandomIt>
void mergeSort(std::vector<int>& v, RandomIt start, RandomIt end) {
    if (end - start <= 1) return;

    auto mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid, end);

    std::vector<int> temp;
    merge(start, mid, mid, end, temp);
    std::move(temp.begin(), temp.end(), start);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    mergeSort(v, v.begin(), v.end());

    for (auto i : v) {
        std::cout << i << ' ';
    }
}

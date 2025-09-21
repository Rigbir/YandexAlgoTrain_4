//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::pair<int, int> partition(std::vector<int>& v, int pivot, int left, int right) {
    int l = left;
    int i = left;
    int r = right + 1;

    while (i < r) {
        if (v[i] < pivot) {
            std::swap(v[i], v[l]);
            ++i;
            ++l;
        } else if (v[i] > pivot) {
            --r;
            std::swap(v[i], v[r]);
        } else {
            ++i;
        }
    }

    return {l, r};
}

void quickSort(std::vector<int>& v, int left, int right) {
    if (left >= right) return;

    int pivot = v[left + rand() % (right - left + 1)];
    auto [l, r] = partition(v, pivot, left, right);

    quickSort(v, left, l - 1);
    quickSort(v, r, right);
}

int main() {
    int n;
    std::cin >> n;
    std::srand(std::time(nullptr));

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    quickSort(v, 0, v.size() - 1);

    for (auto i : v) {
        std::cout << i << ' ';
    }
}
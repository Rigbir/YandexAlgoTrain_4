//
// Created by Marat on 21.09.25.
//

#include <iostream>

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    int s = (b + n - 1) / n;
    std::cout << (a > s ? "YES" : "NO");
}
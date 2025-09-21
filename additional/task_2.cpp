//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

std::pair<int, int> fraction(int a, int b, int c, int d) {
    if (b == 0 || d == 0) throw;

    int m = a * d + c * b;
    int n = b * d;
    int g = gcd(m, n);

    return {m /= g, n /= g};
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto [m, n] = fraction(a, b, c, d);
    std::cout << m << ' ' << n;
}
//
// Created by Marat on 21.09.25.
//

#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, a, b;
        std::cin >> n >> a >> b;

        int minGroups = (n + b - 1) / b;
        int maxGroups = n / a;

        if (minGroups <= maxGroups) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}
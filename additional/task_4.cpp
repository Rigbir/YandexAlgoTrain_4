//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <string>
#include <map>

bool anagram(const std::map<char, int>& m1, const std::map<char, int>& m2) {
    if (m1.size() != m2.size()) return false;

    auto it1 = m1.begin();
    for (auto it2 = m2.begin(); it2 != m2.end(); ++it2, ++it1) {
        if (it1->first != it2->first || it1->second != it2->second) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string line1, line2;
    std::cin >> line1 >> line2;

    std::map<char, int> m1;
    for (auto c : line1) ++m1[c];

    std::map<char, int> m2;
    for (auto c : line2) ++m2[c];

    std::cout << (anagram(m1, m2) ? "YES" : "NO");
}
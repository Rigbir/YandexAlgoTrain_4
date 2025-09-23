//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string inputLine;
    std::cin >> inputLine;

    bool ok = true;
    std::stack<char> st;
    for (char c : inputLine) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                ok = false;
                break;
            }

            if ((c == ')' && st.top() == '(') ||
                (c == ']' && st.top() == '[') ||
                (c == '}' && st.top() == '{')) {
                st.pop();
            } else {
                ok = false;
                break;
            }
        }
    }

    if (!st.empty()) ok = false;

    std::cout << (ok ? "yes" : "no");
}
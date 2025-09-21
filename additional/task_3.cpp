//
// Created by Marat on 21.09.25.
//

#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = acos(-1.0);

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    double rA = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2));
    double rB = std::sqrt(std::pow(x2, 2) + std::pow(y2, 2));

    double thetaA = atan2(y1, x1);
    double thetaB = atan2(y2, x2);
    double d = fabs(thetaA - thetaB);
    double angle = std::min(d, 2*PI - d);

    double firstVar = rA + rB;
    double secondVar = fabs(rA - rB) + std::min(rA, rB) * angle;
    double result = std::min(firstVar, secondVar);

    std::cout << std::fixed << std::setprecision(12) << result;
}
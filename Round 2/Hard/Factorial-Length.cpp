/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    An Integer (A) is given as the only input.
    0 < A <= 10^5
*/

/*
    Logic:
    Find the smallest Number whose factorial will have length equal to A

    Sample Input:
    3

    Sample Output:
    5
*/
#include <iostream>
#include <math.h>
#include <vector>

#define el '\n'
// clang-format on

const double e = 2.7182818284;
const double pi = 3.1415926535;

int findDigits(int n) {
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    double x = ((n * log10(n / e) + log10(2 * pi * n) / 2.0));
    return (int)floor(x) + 1;
}

void solveMyProblem(int n) {
    int low = 0, hi = 2 * n;
    if (findDigits(low) == n) {
        std::cout << low << el;
        return;
    }
    while (low <= hi) {
        int mid = low + (hi - low) / 2;
        if (findDigits(mid) >= n && findDigits(mid - 1) < n) {
            std::cout << mid << el;
            return;
        } else if (findDigits(mid) < n)
            low = mid + 1;
        else
            hi = mid - 1;
    }
    std::cout << low << el;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 1 || n > 100000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
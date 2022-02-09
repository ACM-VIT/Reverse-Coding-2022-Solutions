/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'N' between 0 and 10^9 (Inclusive).
*/

/*
    Logic:
    Find the minimum add or sub to get a power of 2.

    Sample Input:
    1234

    Sample Output:
    210
*/
#include <iostream>
#include <vector>
#include <string>
#define el '\n'

void solveMyProblem(int n) {
    int ans = 0, low = 0, high = 0;
    for (int i = n; i >= 1; i--) {
        if (!(i & (i - 1))) {
            low = i;
            break;
        }
    }
    high = low * 2;
    ans = std::min(abs(n - low), abs(n - high));
    std::cout << ans << el;
}

int main() {
    try {
        int n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 1000000000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

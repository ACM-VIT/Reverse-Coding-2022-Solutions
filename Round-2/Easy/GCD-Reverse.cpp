/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    An Integer (A) is given as the only input.
    0 < A < 10^9
*/

/*
    Logic:
    Take the GCD of the number and its reverse.

    Sample Input:
    1771

    Sample Output:
    1771
*/
#include <iostream>
#include <vector>
#define el '\n'

long long GCD(long long a, long long b) {
    if (b > a)
        return GCD(b, a);
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void solveMyProblem(int n) {
    long long rev = 0, copy = n;
    while (copy > 0)
        rev = (rev * 10) + (copy % 10), copy /= 10;
    std::cout << GCD(n, rev) << el;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 1 || n > 1000000000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

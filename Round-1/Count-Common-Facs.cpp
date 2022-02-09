/*
    Author: Rishu Yadav

    Test Case Description:
    First line contains an integer T (between 1 and 100) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line contains two space seperated numbers a and b where both a and b lie strictly
    between 0 and 10^9(Inclusive)
*/

/*
    Logic:
    Take input of two numbers and find the number of common factors between them.

    Sample Input:
    1
    10 20

    Sample Output:
    4
*/
#include <cmath>
#include <iostream>

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long long commDiv(long long a, long long b) {
    long long n = gcd(a, b), result = 0;
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                result += 1;
            else
                result += 2;
        }
    }
    return result;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        while (n--) {
            long long a, b;
            std::cin >> a;
            if (a <= 0 || a > 1000000000 || !std::cin)
                throw -1;
            std::cin >> b;
            if (b <= 0 || b > 1000000000 || !std::cin)
                throw -1;
            std::cout << commDiv(a, b) << std::endl;
        }
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
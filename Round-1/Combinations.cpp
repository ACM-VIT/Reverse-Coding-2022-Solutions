/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    First line contains an integer T (between 1 and 100) which stands for the number of testcases. 
    The next T lines contain the details for each testcase.
    Each line has 2 integers a and b between 0 and 20 such that b < a
*/

/*
    Logic:
    For each testcase, take two numbers a and b, and find aCb which is given by, a!/ ( (a-b)! * b! )

    Sample Input:
    3
    15 4
    4 2
    19 10

    Sample Output:
    1365
    6
    92378
*/
#include <iostream>

long long factorial(int x) {
    long long result = 1;
    for (int i = 1; i <= x; i++)
        result *= (long long)i;
    return result;
}

int main() {
    try {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 100)
            throw -1;
        for (int t = 0; t < test; t++) {
            int a, b;
            std::cin >> a >> b;
            if (!std::cin || a < 0 || a > 20 || b < 0 || b > 20 || b > a)
                throw -2;
            long long ans = factorial(a) / (factorial(a - b) * factorial(b));
            std::cout << ans << "\n";
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question's description.\n"; }
    return 0;
}

/*
    Author: Aryanam Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 5, inclusive), 
    which describes the number of testcases. 
    Each testcase has 1 line, which contains an integer n (between 1 and 15).
*/

/*
    Logic:
    For each testcase, print the pattern
    For n = 2,
        0
      0 1 0
    0 1 2 1 0
      0 1 0
        0
*/
#include <iostream>


void solve(long long n) {
    int k = 2 * n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++)
            std::cout << " ";
        for (int j = 0; j <= i; j++)
            std::cout << j << " ";
        for (int j = i - 1; j >= 0; j--)
            std::cout << j << " ";
        std::cout << "\n";
        k -= 2;
    }
    k = 2;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++)
            std::cout << " ";
        for (int j = 0; j <= i; j++)
            std::cout << j << " ";
        for (int j = i - 1; j >= 0; j--)
            std::cout << j << " ";
        std::cout << "\n";
        k += 2;
    }
    std::cout << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 5)
            throw -1;
        for (int T = 0; T < testcases; T++) {
            int n;
            std::cin >> n;
            if (!std::cin || n < 1 || n > 15)
                throw -2;
            solve(n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

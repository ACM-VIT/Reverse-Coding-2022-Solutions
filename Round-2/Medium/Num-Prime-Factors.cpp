/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive), 
    which describes the number of testcases.
    Each testcase consists of one integer ranging from 1 to 10^7.
*/

/*
    Logic:
    Find the number of prime factors

    Sample Input:
    1
    4

    Sample Output:
    1
*/
#include <iostream>
#include <math.h>

bool isPrime(int n) {
    for (int i = 2; i * i <= n + 1; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0 && isPrime(i))
            ans++;
    std::cout << ans << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 50)
            throw -1;
        int n;
        for (int T = 0; T < testcases; T++) {
            std::cin >> n;
            if (!std::cin || n < 1 || n > round(pow(10, 7)))
                throw -2;
            solve(n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

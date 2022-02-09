/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive), 
    which describes the number of testcases.
    Each testcase has one integer, ranging from 1 to 10^18
*/

/*
    Logic:
    Smallest number to add/subtract from n to make it a power of 2

    Sample Input:
    1
    3

    Sample Output:
    1
*/
#include <iostream>
#include <math.h>


void solve(long long n) {
    long long p1 = round(log2(n)), p2 = round(log2(n)) + 1;
    long long ans1 = abs(round(pow(2, p1)) - n), ans2 = abs(round(pow(2, p2)) - n);
    if (ans1 < ans2)
        std::cout << ans1 << "\n";
    else
        std::cout << ans2 << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 50)
            throw -1;
        long long n;
        for (int T = 0; T < testcases; T++) {
            std::cin >> n;
            if (!std::cin || n < 1 || n > round(pow(10, 18)))
                throw -2;
            solve(n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

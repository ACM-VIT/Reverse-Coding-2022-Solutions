/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 100, inclusive), 
    which describes the number of testcases. Each testcase has 2 lines.
    The first line of a testcases contains an integer n (between 1 and 5), 
    and the second line contains n integers (between 1 and 10^4).
*/

/*
    Logic:
    For each testcase, find the LCM and GCD of the array elements, and print LCM - GCD

    Sample Input:
    1
    3
    3 5 8

    Sample Output:
    119
*/
#include <iostream>
#include <set>
#include <vector>


long long getGcd(long long x, long long y) {
    if (y == 0)
        return x;
    return getGcd(y, x % y);
}

void solve(std::vector<long long> vi, long long n) {
    long long lcm, gcd;
    lcm = vi[0], gcd = vi[0];
    for (int i = 1; i < n; i++) {
        gcd = getGcd(vi[i], gcd);
        lcm = (vi[i] * lcm) / getGcd(vi[i], lcm);
    }
    std::cout << lcm - gcd << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 100)
            throw -1;
        for (int T = 0; T < testcases; T++) {
            int n;
            std::cin >> n;
            if (!std::cin || n < 1 || n > 5)
                throw -2;
            std::set<long long> s;
            for (int i = 0; i < n; i++) {
                long long tmp;
                std::cin >> tmp;
                s.insert(tmp);
                if (!std::cin || tmp < 1 || tmp > 10000)
                    throw -3;
            }
            std::vector<long long> vi(s.begin(), s.end());
            n = vi.size();
            solve(vi, n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

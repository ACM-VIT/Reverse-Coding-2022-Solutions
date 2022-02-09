/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line has 5 integers a b c d e, where a,b,c,d,e are between 1 and 25

*/

/*
    Logic:
    For each testcase, there are 5 integers - a b c d N.
    Give the first N terms of the series, (Odd terms = AP, Even terms = GP)
    a  b  a+c  b*d  a+2c  b*d*d  a+3c  b*d*d*d  a+4c ...

    Sample Input:
    2 3 3 4 7

    Sample Output:
    2 3 5 12 8 48 11
*/
#include <iostream>

void solve(long long a, long long b, long long c, long long d, long long n) {
    int i = 1;
    for (i = 1; i < n; i++) {
        if (i % 2 == 1) {
            std::cout << a << " ";
            a += c;
        } else {
            std::cout << b << " ";
            b *= d;
        }
    }
    if (i % 2 == 0)
        std::cout << b << "\n";
    else
        std::cout << a << "\n";
}

int main() {
    try {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 150)
            throw -1;
        for (int t = 0; t < test; t++) {
            long long a, b, c, d, n;
            std::cin >> a >> b >> c >> d >> n;
            if (!std::cin || a < 1 || a > 25 || b < 1 || b > 25 || c < 1 || c > 25 || d < 1 || d > 25 || n < 1 ||
                n > 25)
                throw -2;
            solve(a, b, c, d, n);
        }
    } catch (...) { std::cout << "Invalid input. Please check the question description.\n"; }
    return 0;
}

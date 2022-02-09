/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive), 
    which describes the number of testcases.
    Each testcase has two, space separated strings. Each string has length ranging from 1 to 100.
    Each string consists only of letters in lowercase.
*/

/*
    Logic:
    Find the length of the largest common subsequence of 2 strings

    Sample Input:
    1
    hawkeye hulk

    Sample Output:
    2
*/
#include <iostream>
#include <string>
#include <vector>


void solve(std::string a, std::string b, int n1, int n2) {
    std::vector<std::vector<int> > dp(n1 + 1, std::vector<int>(n2 + 1));
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    std::cout << dp[n1][n2] << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 50)
            throw -1;
        int n1, n2;
        std::string a, b;
        for (int T = 0; T < testcases; T++) {
            std::cin >> a >> b;
            n1 = a.length(), n2 = b.length();
            if (!std::cin || n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100)
                throw -2;
            int i1 = 0, i2 = 0;
            while (i1 < n1 || i2 < n2) {
                if (i1 < n1) {
                    if (a[i1] >= 'a' && a[i1] <= 'z')
                        i1++;
                    else
                        throw -3;
                }
                if (i2 < n2) {
                    if (b[i2] >= 'a' && b[i2] <= 'z')
                        i2++;
                    else
                        throw -4;
                }
            }
            solve(a, b, n1, n2);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

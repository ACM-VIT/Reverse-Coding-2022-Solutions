/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    First line contains an integer T (between 1 and 20) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line has one string of length between 1 and 250, and consists only of lowercase letters.
*/

/*
    Logic:
    For each testcase print the string with letters at the fibonacci sequence's index as
    capital letters. Treating the first letter as index 0.

    Sample Input:
    1
    helloworld

    Sample Output:
    HELLoWorLd
*/
#include <iostream>
#include <math.h>
#include <string>

int main() {
    try {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 20)
            throw -1;
        for (int t = 0; t < test; t++) {
            std::string s;
            std::cin >> s;
            size_t n = s.length();
            if (!std::cin || n < 1 || n > 250)
                throw -1;
            char *result = new char[n + 1];
            for (int i = 0; i < n; i++) {
                if (!(s[i] >= 'a' && s[i] <= 'z'))
                    throw -2;
                result[i] = s[i];
            }
            int prev = 1, current = 2;
            result[0] = result[0] - 32;
            std::cout << result[0];
            if (n >= 2) {
                result[1] = result[1] - 32;
                std::cout << result[1];
            }
            for (int i = 2; i < n; i++) {
                if (i == current) {
                    result[i] = result[i] - 32;
                    int tmp = current;
                    current = current + prev, prev = tmp;
                }
                std::cout << result[i];
            }
            std::cout << "\n";
            delete[] result;
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question description.\n"; }
    return 0;
}

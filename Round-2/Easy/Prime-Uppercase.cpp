/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 10, inclusive), which 
    describes the number of testcases. Each testcase has 1 line, which contains a string of 
    length ranging from 1 to 10^3. All characters are letters in lowercase.
*/

/*
    Logic:
    For each testcase, capitalize the letters at a prime index

    Sample Input:
    1
    helloworld

    Sample Output:
    heLLoWoRld
*/
#include <iostream>
#include <string>
#include <vector>

std::vector<bool> prime(100001, true);

void generate() {
    prime[0] = false, prime[1] = false;
    int n = 100000;
    for (int p = 2; p * p <= n; p++)
        if (prime[p])
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
}

void solve(std::string s, int n) {
    char c;
    for (int i = 0; i < n; i++) {
        if (prime[i])
            std::cout << char(s[i] - 32);
        else
            std::cout << s[i];
    }
    std::cout << "\n";
}

int main() {
    generate();
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 10)
            throw -1;
        int n;
        for (int T = 0; T < testcases; T++) {
            std::string s;
            std::cin >> s;
            n = s.length();
            if (!std::cin || n < 1 || n > 1000)
                throw -2;
            for (int i = 0; i < n; i++)
                if (s[i] < 'a' || s[i] > 'z')
                    throw -3;
            solve(s, n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive), 
    which describes the number of testcases.
    Each testcase has one line, which consists of a string whose length ranges from 1 to 100. 
    Each character in the string is a letter in lowercase.
*/

/*
    Logic:
    Print the number of moves it would require to convert a
    string into a palindrome (for each string element)


    Sample Input:
    1
    abc

    Sample Output:
    2 0 2
*/
#include <iostream>
#include <string>


void solve(std::string s, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << abs(s[i] - s[n - i - 1]) << " ";
    }
    std::cout << "\n";
}

int main() {
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 50)
            throw -1;
        int n;
        for (int T = 0; T < testcases; T++) {
            std::string s;
            std::cin >> s;
            n = s.length();
            if (!std::cin || n < 1 || n > 100)
                throw -2;
            for (int i = 0; i < n; i++)
                if (s[i] < 'a' || s[i] > 'z')
                    throw -3;
            solve(s, n);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

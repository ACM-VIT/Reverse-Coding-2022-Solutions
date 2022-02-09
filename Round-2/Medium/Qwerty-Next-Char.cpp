/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive), 
    which describes the number of testcases.
    Each testcase consists of one line, which contains a string with length ranging from 1 to 100.
    Each string consists of letters in lowercase.
*/

/*
    Logic:
    For all characters of a string, print the one that comes next on a qwerty keyboard.

    Sample Input:
    1
    tony

    Sample Output:
    ypmu
*/
#include <iostream>
#include <math.h>
#include <unordered_map>

void solve(std::string s, int n, std::unordered_map<char, char> map) {
    for (int i = 0; i < n; i++)
        std::cout << map[s[i]];
    std::cout << "\n";
}

int main() {
    std::unordered_map<char, char> map;
    std::string values = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < 26; i++)
        map[values[i]] = values[(i + 1) % 26];
    try {
        int testcases;
        std::cin >> testcases;
        if (!std::cin || testcases < 1 || testcases > 50)
            throw -1;
        int n;
        std::string s;
        for (int T = 0; T < testcases; T++) {
            std::cin >> s;
            n = s.length();
            if (!std::cin || n < 1 || n > 100)
                throw -2;
            for (int i = 0; i < n; i++)
                if (s[i] < 'a' || s[i] > 'z')
                    throw -3;
            solve(s, n, map);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

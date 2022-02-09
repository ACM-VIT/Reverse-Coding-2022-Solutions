/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single String 'S' of length between 1 and 6 (Inclusive).
    Note:
    All Characters of the String are ONLY Upper-Case Characters of the English Lexicon
*/

/*
    Logic:
    Find the dictionary order of appearance of the string

    Sample Input:
    AA

    Sample Output:
    27
*/
#include <iostream>
#include <vector>
#include <string>
#define el '\n'

void solveMyProblem(std::string s) {
    int p = 1, c = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        c = c + ((s[i] - 'A' + 1) * (p));
        p *= 26;
    }
    std::cout << c << el;
}

int main() {
    try {
        std::string s;
        std::cin >> s;
        int n = (int)s.length();
        if (!std::cin || (n < 1 || n > 6))
            throw -1;
        for (char i : s)
            if (i > 'Z' || i < 'A')
                throw -1;
        solveMyProblem(s);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

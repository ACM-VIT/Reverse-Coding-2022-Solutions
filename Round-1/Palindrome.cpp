/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The first line contains an integer T (1 <= T <= 100), which stands for the number of testcases.
    Each testcase contains a string of length ranging from 1 to 100.
*/

/*
    Logic:
    Take a string as input and check if it is palindrome or not. 

    Sample Input:
    2
    Hello
    racecar

    Sample Output:
    NO
    YES
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#define el '\n'

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        while (n--) {
            std::string x, y;
            std::cin >> x;
            if (!std::cin || x.length() < 1 || x.length() > 100)
                throw -1;
            y = x;
            reverse(y.begin(), y.end());
            if (y == x)
                std::cout << "YES" << el;
            else
                std::cout << "NO" << el;
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question description." << std::endl; }
    return 0;
}
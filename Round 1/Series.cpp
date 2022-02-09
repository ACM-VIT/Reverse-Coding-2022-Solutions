/*
    Author: Rishu Yadav

    Test Case Description:
    First line contains an integer T (between 1 and 100) which stands for the number of testcases.
    The next T lines contain the details for each testcase where each test case includes:
    Two integers with first value between 1 and 10^4 (Inclusive) and the second value between 0 and 10^5 (Inclusive).
*/

/*
    Logic:
    Take two numbers as input x and y. Print a series of the form x*i+1 where i is between 1 and y (Inclusive).

    Sample Input:
    3
    2 5
    3 4
    6 8

    Sample Output:
    3
    5
    7
    9
    11
    4
    7
    10
    13
    7
    13
    19
    25
    31
    37
    43
    49
*/
#include <iostream>
#include <math.h>
#define el '\n'

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        while (n--) {
            int x, y;
            std::cin >> x;
            if (!std::cin || x < 1 || x > 10000)
                throw -1;
            std::cin >> y;
            if (!std::cin || y < 1 || y > 100000)
                throw -1;
            for (int i = 1; i <= y; i++)
                std::cout << x * i + 1 << el;
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question description." << std::endl; }
    return 0;
}
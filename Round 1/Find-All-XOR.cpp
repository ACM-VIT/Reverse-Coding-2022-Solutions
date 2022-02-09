/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    First Line: A Single Integer T Denoting Number Of Tests, T <= 2000 For Every Test-Case.
    Next T Lines, Two Integers Between 0 and 10^6 (Inclusive).
*/

/*
    Logic:
    Take two numbers and find their XOR.

    Sample Input:
    1
    85 59

    Sample Output:
    110
*/
#include <iostream>
#include <math.h>
#define el '\n'

int main() {
    try {
        int t;
        std::cin >> t;
        if (!std::cin || t < 0 || t > 2000)
            return 1;
        while (t--) {
            int x, y;
            std::cin >> x;
            if (!std::cin || x < 0 || x > 1000000)
                throw -1;
            std::cin >> y;
            if (!std::cin || y < 0 || y > 1000000)
                throw -1;
            std::cout << (int)(x ^ y) << el;
        }
    } catch (...) {
        std::cout << "Invalid input. Please refer to the question description." << std::endl;
        return 0;
    }
}
/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line of the input contains an integer T (between 1 and 50, inclusive),
    which describes the number of testcases.
    Each testcase has one integer, ranging from 1 to 10^18
*/

/*
    Logic:
    Smallest number to add/subtract from n to make it a power of 2

    Sample Input:
    1
    3

    Sample Output:
    1
*/
#include <iostream>
#include <math.h>

void solveMyProblem(int n) {
    int ans = 0, low = 0, high = 0;
    for (int i = n; i >= 1; i--) {
        if (!(i & (i - 1))) {
            low = i;
            break;
        }
    }
    high = low * 2;
    ans = std::min(abs(n - low), abs(n - high));
    std::cout << ans << std::endl;
}

int main() {
    try {
        int n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 1000000000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
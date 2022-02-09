/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The first line contains an integer T (1 <= T <= 100), which is the number of testcases.
    Each testcase contains a single Integer 'N' between 3 and 100 (Inclusive). (N will always be odd.)
    Followed by 'N' consecutive integers. 
    Each Integer varies between 1 and 10^4

*/

/*
    Logic:
    Take XOR of all the elements

    Sample Input:
    1
    5
    1 3 4 1 3

    Sample Output:
    4
*/
#include <iostream>
#include <string>
#include <vector>
#define el '\n'

void solveMyProblem(long long n, std::vector<long long> &arr) {
    long long k = arr[0];
    for (long long i = 1; i < n; i++)
        k = k ^ arr[i];
    std::cout << k << el;
}

int main() {
    try {
        long long t;
        std::cin >> t;
        if (!std::cin || (t < 0 || t > 100))
            throw -1;
        while (t--) {
            long long n;
            std::cin >> n;
            if (!std::cin || (n < 3 || n > 100) || (n % 2 == 0))
                throw -1;
            std::vector<long long> arr(n);
            for (long long i = 0; i < n; i++) {
                std::cin >> arr[i];
                if ((!std::cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 10000))
                    throw -1;
            }
            solveMyProblem(n, arr);
        }
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
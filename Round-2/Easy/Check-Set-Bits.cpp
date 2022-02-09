/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries. 
    Each Query is comprised 1 Integer (A)
    0 < A < 10^9
*/

/*
    Logic:
    Check the set bits of a number.

    Sample Input:
    3
    420
    1729
    12345678


    Sample Output:
    4
    5
    12
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<long long> &arr) {
    for (long long &i : arr) {
        int ans = 0;
        while (i > 0) {
            if (i & 1)
                ans++;
            i /= 2;
        }
        std::cout << ans << el;
    }
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        std::vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            std::cin >> arr[i];
            if ((!std::cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
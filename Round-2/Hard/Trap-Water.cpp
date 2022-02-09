/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The First Line will have 1 integer, 'N' 
    Where(1 <= N <= 10^5)
    Second Line will have 'N' spaced integers (A1, A2, ... AN)
    Where (0 <= Ai <= 10^3) Ai -> Ith Integer.
*/

/*
    Logic:
    Trapping Rain Water in recesses.

    Sample Input:
    7
    3 2 1 0 1 2 3

    Sample Output:
    9
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<long long> &arr, long long n) {
    long long sze = n - 1, prev = arr[0], prevIdx = 0, ans = 0, temp = 0;
    for (int i = 1; i <= sze; i++) {
        if (arr[i] >= prev)
            prev = arr[i], prevIdx = i, temp = 0;
        else
            ans += prev - arr[i], temp += prev - arr[i];
    }
    if (prevIdx < sze) {
        ans -= temp, prev = arr[sze];
        for (int i = sze; i >= prevIdx; i--) {
            if (arr[i] < prev)
                ans += prev - arr[i];
            else
                prev = arr[i];
        }
    }
    std::cout << ans << el;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100000))
            throw -1;
        std::vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            std::cin >> arr[i];
            if ((!std::cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(arr, n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

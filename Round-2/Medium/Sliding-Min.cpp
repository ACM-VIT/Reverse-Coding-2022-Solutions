/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    The First Line will have 2 integers, 'N' & 'K'
    Where(1 <= N <= 10^5) & (1 <= K <= N).

    Second Line will have 'N' spaced integers (A1, A2, ... AN)
    Where (1 <= Ai <= 10^9) Ai -> Ith Integer.
*/

/*
    Logic:
    Find the Sliding Window Minimum till K.

    Sample Input:
    9 3
    1 8 7 2 4 3 9 6 4


    Sample Output:
    1 2 2 2 3 3 4
*/
#include <deque>
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(int n, int k, std::vector<int> &arr) {
    std::deque<long long int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.front()] >= arr[i])
            dq.pop_front();
        dq.push_front(i);
    }
    std::cout << arr[dq.back()] << " ";
    for (int i = k; i < n; i++) {
        while (!dq.empty() && dq.back() <= (i - k))
            dq.pop_back();
        while (!dq.empty() && arr[dq.front()] >= arr[i])
            dq.pop_front();
        dq.push_front(i);
        std::cout << arr[dq.back()] << " ";
    }
    std::cout << el;
}

int main() {
    try {
        int n, k;
        std::cin >> n >> k;
        if (!std::cin || (n < 0 || n > 100000) || (k > n))
            throw -1;
        std::vector<int> arr(n);
        for (long long i = 0; i < n; i++) {
            std::cin >> arr[i];
            if ((!std::cin && i <= n - 1) || (arr[i] < 1 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(n, k, arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

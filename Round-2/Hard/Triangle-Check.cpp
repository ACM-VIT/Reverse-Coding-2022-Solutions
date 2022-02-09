/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries.


    Each Query is comprised 3 Lines

    Each Line of the query will have 2 Integers (A, B)
    -10^9 < A < 10^9
    -10^9 < B < 10^9
*/

/*
    Logic:
    Do the coordinates make a right angle triangle?

    Sample Input:
    2
    1 2
    3 4
    5 6

    3 8
    3 4
    7 4

    Sample Output:
    NO
    YES
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<std::vector<long long> > &hold) {
    for (std::vector<long long> arr : hold) {
        int A = ((arr[2] - arr[0]) * (arr[2] - arr[0])) + ((arr[3] - arr[1]) * (arr[3] - arr[1]));
        int B = ((arr[4] - arr[2]) * (arr[4] - arr[2])) + ((arr[5] - arr[3]) * (arr[5] - arr[3]));
        int C = ((arr[4] - arr[0]) * (arr[4] - arr[0])) + ((arr[5] - arr[1]) * (arr[5] - arr[1]));
        if ((A > 0 && B > 0 && C > 0) && (A == (B + C) || B == (A + C) || C == (A + B)))
            std::cout << "YES" << el;
        else
            std::cout << "NO" << el;
    }
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 10))
            throw -1;
        std::vector<std::vector<long long> > arr(n);
        for (long long i = 0; i < n; i++) {
            std::vector<long long> hold(6);
            for (int j = 0; j < 6; j++) {
                std::cin >> hold[j];
                if ((!std::cin && j <= 5) || (hold[j] < -1000000000 || hold[j] > 1000000000))
                    throw -1;
            }
            arr[i] = hold;
        }
        solveMyProblem(arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

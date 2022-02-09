/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries. 
    Each Query is comprised 2 Integers (A, B)
    0 < A < 10^9
    0 < B < 10^8
*/

/*
    Logic:
    Do A % B

    Sample Input:
    3
    7892 667
    12345 6789
    314159 16170

    Sample Output:
    555
    5556
    6929
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<std::pair<long long, long long> > &arr) {
    for (std::pair<long long, long long> i : arr)
        std::cout << i.first % i.second << el;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        std::vector<std::pair<long long, long long> > arr(n);
        for (long long i = 0; i < n; i++) {
            std::cin >> arr[i].first;
            if ((!std::cin && i <= n - 1) || (arr[i].first < 1 || arr[i].first > 1000000000))
                throw -1;
            std::cin >> arr[i].second;
            if ((!std::cin && i <= n - 1) || (arr[i].second < 1 || arr[i].second > 100000000))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

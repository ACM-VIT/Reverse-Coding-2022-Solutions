/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries.
    Each Query is comprised 2 Integers (A, B)
    0 <= A < 100
    0 <= B < 10
*/

/*
    Logic:
    Do A ^ B

    Sample Input:
    3
    7 4
    1 8
    5 9

    Sample Output:
    2401
    1
    1953125
*/

#include <iostream>
#include <vector>
#define el '\n'

long long pwr(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}

void solveMyProblem(std::vector<std::pair<long long, long long> > &arr) {
    for (std::pair<long long, long long> i : arr)
        std::cout << pwr(i.first, i.second) << el;
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
            if ((!std::cin && i != n) || (arr[i].first < 0 || arr[i].first > 99))
                throw -1;
            std::cin >> arr[i].second;
            if ((!std::cin && i != n) || (arr[i].second < 0 || arr[i].second > 9))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
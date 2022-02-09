/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries.
    Each Query is an Integer that varies between 0 and 10^9
*/

/*
    Logic:
    Take or of all the digits of the number

    Sample Input:
    3
    12345
    314159
    27143

    Sample Output:
    7
    15
    7
*/
#include <iostream>
#include <string>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<long long> &arr) {
    for (long long i : arr) {
        std::string n = std::to_string(i);
        long long k = 0;
        for (char i : n)
            k |= (i - '0');
        std::cout << k << el;
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
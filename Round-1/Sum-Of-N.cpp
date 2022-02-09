/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries. 
    Each Query is an Integer that varies between 1 and 10^5

*/

/*
    Logic:
    Sum of number from 1 to n
    
    Sample Input:
    3
    420
    314159
    69

    Sample Output:
    88410
    49348095720
    2415
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<long long> &arr) {
    for (long long i : arr)
        std::cout << (i * (i + 1)) / 2 << el;
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
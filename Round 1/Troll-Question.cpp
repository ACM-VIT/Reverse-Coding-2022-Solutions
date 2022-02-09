/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'T' between 1 and 100 (Inclusive).
    Followed by 'T' consecutive Queries. 
    Each Query is an Integer that varies between -10^9 and +10^9

*/

/*
    Logic:
    If N > 42069 Print "Snoop Dogg"
    Else If N < 42069 Print "Martha Stewart"
    Else Print "I am being Trolled" 
    
    Sample Input:
    3
    -12345
    314159
    101010

    Sample Output:
    Martha Stewart
    Snoop Dogg
    Snoop Dogg
*/
#include <iostream>
#include <vector>
#define el '\n'

void solveMyProblem(std::vector<long long> &arr) {
    for (long long i : arr) {
        if (i > 42069)
            std::cout << "Snoop Dogg" << el;
        else if (i < 42069)
            std::cout << "Martha Stewart" << el;
        else
            std::cout << "I am being Trolled" << el;
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
            if ((!std::cin && i <= n - 1) || (arr[i] < -1000000000 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

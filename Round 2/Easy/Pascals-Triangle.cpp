/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    Single Integer 'N' between 1 and 20 (Inclusive).
*/

/*
    Logic:
    Print n rows of pascal’s triangle

    Sample Input:
    3

    Sample Output:
    1 
    1 1 
    1 2 1 
*/
#include <iostream>
#include <vector>
#define el '\n'
// clang-format on

void solveMyProblem(long long n) {
    std::vector <std::vector <int> > arr(n, std::vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
                std::cout << 1 << " ";
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << el;
    }
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 20))
            throw -1;
        solveMyProblem(n);
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

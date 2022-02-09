/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    The first line consists of an integer T (between 1 and 10) which stands for number of testcases. 
    The next T lines contain the details for each testcase.
    Each line has one integer n, where n is between 1 and 25

*/

/*
    Logic:
    Print numbers in the following pattern -
    For input of 4,

    1 2 3 4 5 4 3 2 1
    2 3 4 5 1 5 4 3 2
    3 4 5 1 2 1 5 4 3
    4 5 1 2 3 2 1 5 4
    5 1 2 3 4 3 2 1 5
    4 5 1 2 3 2 1 5 4
    3 4 5 1 2 1 5 4 3
    2 3 4 5 1 5 4 3 2
    1 2 3 4 5 4 3 2 1

    Sample Input:
    1
    4

    Sample Output:
    1 2 3 4 5 4 3 2 1
    2 3 4 5 1 5 4 3 2
    3 4 5 1 2 1 5 4 3
    4 5 1 2 3 2 1 5 4
    5 1 2 3 4 3 2 1 5
    4 5 1 2 3 2 1 5 4
    3 4 5 1 2 1 5 4 3
    2 3 4 5 1 5 4 3 2
    1 2 3 4 5 4 3 2 1
*/
#include <iostream>
#include <vector>

void solve(int n) {
    std::vector<std::vector<int> > lower_table;
    for (int R = 0; R <= n; R++) {
        std::vector<int> row(2 * n + 1);
        int j = 0;
        int start = R + 1;
        for (int i = start; i <= n + 1; i++) {
            row[j++] = i;
            std::cout << i << " ";
        }
        for (int i = 1; i < start; i++) {
            row[j++] = i;
            std::cout << i << " ";
        }
        for (int i = n - 1; i >= 0; i--) {
            row[j++] = row[i];
            std::cout << row[i];
            if (i != 0)
                std::cout << " ";
        }
        std::cout << "\n";
        lower_table.push_back(row);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * n; j++)
            std::cout << lower_table[i][j] << " ";
        std::cout << lower_table[i][2 * n] << "\n";
    }
    std::cout << "\n";
}

int main() {
    try {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 10)
            throw -1;
        for (int t = 0; t < test; t++) {
            int n;
            std::cin >> n;
            if (!std::cin || n < 1 || n > 25)
                throw -2;
            solve(n);
        }
    } catch (...) { std::cout << "Invalid input. Please check the question description.\n"; }
    return 0;
}

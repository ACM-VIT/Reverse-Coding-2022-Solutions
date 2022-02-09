/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    First line contains an integer T (between 1 and 10) which stands for the number of testcases.
    The first line of each testcase consists of integer n, m (between 1 and 25).
    The next n lines contain m integers each. Each integer lies between 1 and 1000.
*/

/*
    Logic:
    For each testcase, there is one matrix, whose spiral form should be printed.

    Sample Input:
    1
    5 5
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25


    Sample Output:
    1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
*/
#include <iostream>
#include <vector>

void solve(std::vector<std::vector<int> > matrix, int n, int m) {
    int i = 0, j = 0;
    int xLimit = n - 1, yLimit = m - 1;
    int xLower = 0, yLower = 1;
    int incrementingI = 0;
    int visited = 0, total = n * m;
    while (visited < total) {
        std::cout << matrix[i][j] << " ";
        visited++;
        if (incrementingI == 0) {
            if (j < yLimit) {
                j++;
            } else {
                incrementingI = 1;
                yLimit--, i++;
            }
        } else if (incrementingI == 1) {
            if (i < xLimit) {
                i++;
            } else {
                incrementingI = 2;
                xLimit--, j--;
            }
        } else if (incrementingI == 2) {
            if (j > xLower) {
                j--;
            } else {
                incrementingI = 3;
                xLower++, i--;
            }
        } else if (incrementingI == 3) {
            if (i > yLower) {
                i--;
            } else {
                incrementingI = 0;
                yLower++, j++;
            }
        }
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
            int n, m;
            std::cin >> n >> m;
            std::vector<std::vector<int> > matrix(n);
            if (!std::cin || n < 1 || n > 25 || m < 1 || m > 25)
                throw -2;
            for (int i = 0; i < n; i++) {
                std::vector<int> row(m);
                for (int j = 0; j < m; j++) {
                    std::cin >> row[j];
                    if (!std::cin || row[j] < 1 || row[j] > 1000)
                        throw -3;
                }
                matrix[i] = row;
            }
            solve(matrix, n, m);
        }
    } catch (...) { std::cout << "Invalid input. Please check the question description.\n"; }
    return 0;
}
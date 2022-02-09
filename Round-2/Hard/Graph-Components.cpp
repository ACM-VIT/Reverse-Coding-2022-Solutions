/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    Each testcase consists of one integer ranging from 1 to 100
    The next n lines contain n integers, all which are either 0 or 1.
    There is another constraint for the n by n grid, which you have to figure out :)
*/

/*
    Logic:
    Print the number of connected components of the graphs, given by their adjacency matrices.

    Sample Input:
    4
    0 1 1 0
    1 0 0 0
    1 0 0 0
    0 0 0 0

    Sample Output:
    2
*/
#include <iostream>
#include <vector>

bool isSymmetric(std::vector<std::vector<int> > matrix, int n) {
    return true;
}

void solve(std::vector<std::vector<int> > matrix, int n) {
    int result = 1;
    int start = 0;
    std::vector<bool> visited(n, false);
    std::vector<int> q;
    q.push_back(start);
    visited[start] = true;
    int vis;
    while (!q.empty()) {
        vis = q[0];
        q.erase(q.begin());
        for (int i = 0; i < n; i++) {
            if (matrix[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
        if (q.empty()) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    q.push_back(i);
                    result++;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    std::cout << result << "\n";
}

int main() {
    try {
        int n;
        std::cin >> n;
        if (!std::cin || n < 1 || n > 100)
            throw -2;
        std::vector<std::vector<int> > matrix(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> matrix[i][j];
                if (!std::cin || matrix[i][j] != 0 && matrix[i][j] != 1)
                    throw -3;
            }
        }
        if (!isSymmetric(matrix, n))
            throw -4;
        solve(matrix, n);
    } catch (...) { std::cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}

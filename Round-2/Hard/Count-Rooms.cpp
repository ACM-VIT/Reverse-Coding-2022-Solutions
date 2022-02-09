/*
    Author: Jay Kaoshik (@JayKTech)

    Test Case Description:
    Given Two Integers N and M (between 1 and 44, inclusive).
    Starting From The Second Line, A Matrix Of Dimension N x M Is Given.
    The Matrix Is A Character Matrix Only Comprising Of '.' or '#'.
*/

/*
    Logic:
    Given, A House Plan In The Form Of A Matrix.
    '.' Represents Floor & '#' Represents Wall.
    Count The Number Of Rooms.

    Sample Input:
    7 12
    ..##..##.#.#
    ##..#.#..#.#
    ############
    #..#...#.#.#
    ####.#.#.#.#
    #..#...#.#.#
    ############

    Sample Output:
    10
*/
#include <iostream>
#include <vector>
#define el '\n'

long long n, m;
char plan[1001][1001];
bool visit[1001][1001];
std::vector<std::vector<long long> > r(4, std::vector<long long>(2, 0));

void dfs(long long i, long long j) {
    visit[i][j] = true;
    for (std::vector<long long> k : r) {
        long long x = i + k[0], y = j + k[1];
        if (x >= 0 && x < n && y >= 0 && y < m)
            if (!visit[x][y] && plan[x][y] == '.')
                dfs(x, y);
    }
}

void solve() {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (!visit[i][j] && plan[i][j] == '.') {
                count += 1;
                dfs(i, j);
            }
        }
    }
    std::cout << count << el;
}

int main() {
    try {
        for (int i = 0; i < 4; i++) {
            if (i == 0)
                r[i][0] = 0, r[i][1] = 1;
            else if (i == 1)
                r[i][0] = 1, r[i][1] = 0;
            else if (i == 2)
                r[i][0] = -1, r[i][1] = 0;
            else
                r[i][0] = 0, r[i][1] = -1;
        }
        std::cin >> n;
        if (!std::cin || (n < 1 || n > 1000))
            throw -1;
        std::cin >> m;
        if (!std::cin || (m < 1 || m > 1000))
            throw -1;
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                std::cin >> plan[i][j];
                if (!std::cin || (plan[i][j] != '.' && plan[i][j] != '#'))
                    throw -1;
            }
        }
        solve();
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
/*
    Author: Rishu Yadav

    Test Case Description:
    First line contains an integer T (between 1 and 500) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line has exactly 3 space seperated numbers each between 1 and 10,000(Inclusive)
*/

/*
    Logic:
    Find biwise and of 3 numbers if bitwise "AND" is 0 print "YES" else print "NO"

    Sample Input:
    4
    2 5 8
    11 111 1
    12 20 40
    15 20 25

    Sample Output:
    YES
    NO
    YES
    YES
*/
#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
    try {
        int n;
        std::cin >> n;
        if (n > 500 || n < 1)
            throw -2;
        while (n--) {
            int a, b, c;
            std::cin >> a >> b >> c;
            if (!std::cin || a > 10000 || b > 10000 || c > 10000 || a < 0 || b < 0 || c < 0)
                throw -1;
            int ans = a & b & c;
            if (!ans)
                std::cout << "YES \n";
            else
                std::cout << "NO\n";
        }
    } catch (...) {
        std::cout << "Invalid Input. Please Check The Question Description." << std::endl;
        return 0;
    }
}

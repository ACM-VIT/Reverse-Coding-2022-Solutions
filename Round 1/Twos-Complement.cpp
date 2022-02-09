/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    First line contains an integer T (between 1 and 500) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line has exactly 1 number (ranging between 0 and 10^11)

*/

/*
    Logic:
    Convert the numeber into binary, find 2s complement and return output back in decimal.

    Sample Input:
    5
    20
    40
    15
    100
    2000

    Sample Output:
    12
    24
    1
    28
    48
*/
#include <algorithm>
#include <iostream>
#include <string>
#define el '\n'

std::string addBinary(std::string A, std::string B) {
    if (A.length() > B.length())
        return addBinary(B, A);
    int diff = B.length() - A.length();
    std::string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
    A = padding + A;
    std::string res;
    char carry = '0';
    for (int i = A.length() - 1; i >= 0; i--) {
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        } else if (A[i] == '0' && B[i] == '0') {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        } else if (A[i] != B[i]) {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end());
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}

int main() {
    try {
        long long testcases;
        std::cin >> testcases;
        if (testcases <= 0 || testcases > 500)
            throw -1;
        while (testcases--) {
            long long n;
            std::cin >> n;
            if (!std::cin || n > 100000000000)
                throw -2;
            std::string s = "";
            while (n > 0) {
                s += ((n % 2 == 0) ? "0" : "1");
                n = n >> 1;
            }
            reverse(s.begin(), s.end());
            std::string revNum = s;
            for (auto &i : revNum)
                i = (i == '1') ? '0' : '1';
            std::string ans = addBinary(revNum, "1");
            std::cout << stoi(ans, 0, 2) << el;
        }
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

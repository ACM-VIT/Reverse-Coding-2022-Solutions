/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    First Line: Single Integer T Denoting Number Of Tests Where T=2000 In Every Test-Case.
    For The Next T Lines, Single integer between 0 and 10^6 (Inclusive).
*/

/*
    Logic:
    Take an integer as input and find the length of its binary form.

    Sample Input:
    1
    10

    Sample Output:
    4
*/
#include <bitset>
#include <iostream>
#include <math.h>
#include <string>
#define el '\n'

int dtb(int n) {
    std::string s = std::bitset<64>(n).to_string();
    size_t loc1 = s.find('1');
    if (loc1 != std::string::npos)
        return (int)s.substr(loc1).length();
    return 0;
}

int main() {
    try {
        int n;
        std::cin >> n;
        if (!std::cin || n < 0 || n > 2000)
            throw -1;
        while (n--) {
            int x;
            std::cin >> x;
            if (!std::cin || x < 0 || x > 1000000)
                throw -1;
            std::cout << dtb(x) << el;
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question description." << std::endl; }
    return 0;
}

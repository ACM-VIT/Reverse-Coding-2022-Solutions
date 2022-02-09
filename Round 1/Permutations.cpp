/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    First Line: Single Integer T Denoting Number Of Tests Where T=2000 In Every Test-Case.
    For The Next T Lines, Each Line Has A String Of Length 20 Formed Of Lowercase Alphabets.
*/

/*
    Logic:
    Check the number of distinct permutations of a given string for each testcase

    Sample Input:
    1
    code

    Sample Output:
    24
*/
#include <iostream>
#include <string>
#include <vector>
#define el   '\n'

long long fact(int n) {
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

long long perm(std::string str) {
    long long length = (long long)str.length();
    std::vector<int> freq(26, 0);
    for (int i = 0; i < length; i++)
        freq[str[i] - 'a']++;
    long long f = 1;
    for (int i = 0; i < 26; i++)
        f *= fact(freq[i]);
    return (long long)(fact((long long)length) / f);
}

int main() {
    try {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 50000)
            throw -1;
        for (int t = 0; t < test; t++) {
            std::string s;
            std::cin >> s;
            int n = (int)s.length();
            if (!std::cin || n < 1 || n > 20)
                throw -1;
            for (int i = 0; i < n; i++)
                if (s[i] < 'a' || s[i] > 'z')
                    throw -2;
            long long res = perm(s);
            std::cout << res << el;
        }
    } catch (...) { std::cout << "Invalid input. Please refer to the question description." << el; }
    return 0;
}

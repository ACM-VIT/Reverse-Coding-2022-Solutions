/*
    Author: Rehber Moin (@DocFlex)

    Test Case Description:
    First line contains an integer T (between 1 and 100) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line contains two space seperated non-null strings with string length between 1 and 100 (Inclusive).
*/

/*
    Logic:
    Check if the two strings are anagram or not.
    (An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.) Alternatively, Sort the String and Check Equality.

    Sample Input:
    1
    astronomer moonstarer

    Sample Output:
    YES
*/
#include <iostream>
#include <string>
#include <unordered_map>

bool checkAnagram(std::string a, std::string b) {
    size_t len1 = a.length(), len2 = b.length();
    if (len1 != len2)
        return false;
    std::unordered_map<char, int> mp;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]]++, mp[b[i]]--;
    for (auto it : mp)
        if (it.second)
            return false;
    return true;
}

int main() {
    try {
        long long n;
        std::cin >> n;
        if (!std::cin || (n < 0 || n > 100))
            throw -1;
        while (n--) {
            std::string a, b;
            std::cin >> a;
            if (!std::cin || a.length() > 100)
                throw -1;
            std::cin >> b;
            if (!std::cin || b.length() > 100)
                throw -1;
            if (checkAnagram(a, b))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}
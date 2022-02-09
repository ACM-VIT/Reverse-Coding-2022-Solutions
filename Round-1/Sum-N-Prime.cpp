/*
    Author: Aryaman Kolhe (@ChasmicCoder)

    Test Case Description:
    First line contains an integer T (between 1 and 1000) which stands for the number of testcases.
    The next T lines contain the details for each testcase.
    Each line has one number between 1 and 10,000

*/

/*
    Logic:
    Find the sum of prime numbers till n(inclusive)
    For Example:
    2-> sum of prime numbers till 2 = 2
    3-> sum of prime numbers till 3 = 2+3=5
    5-> sum of prime numbers till 5 = 2+3+5=10


    Sample Input:
    5
    2
    5
    13
    15
    20

    Sample Output:
    2
    10
    41
    41
    77
*/
#include <cmath>
#include <cstring>
#include <iostream>

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int k = 2; k * k <= n; k++)
        if (n % k == 0)
            return false;
    return true;
}

int sumOfPrimes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (isPrime(i))
            sum += i;
    return sum;
}

int main() {
    try {
        int k;
        std::cin >> k;
        if (k > 1000 || k <= 0)
            throw -2;
        while (k--) {
            int n;
            std::cin >> n;
            if (!std::cin || n < 0 || n > 10000)
                throw -1;
            std::cout << sumOfPrimes(n) << "\n";
        }
    } catch (...) { std::cout << "Invalid Input. Please Check The Question Description." << std::endl; }
    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Function to perform modular exponentiation
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        // Count of even-indexed positions
        long long evenCount = (n + 1) / 2;
        // Count of odd-indexed positions
        long long oddCount = n / 2;
        
        // Calculate 5^evenCount % MOD and 4^oddCount % MOD
        long long powerOf5 = modExp(5, evenCount, MOD);
        long long powerOf4 = modExp(4, oddCount, MOD);
        
        // Multiply the results and take modulo
        return (powerOf5 * powerOf4) % MOD;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    long long n1 = 1;
    long long n2 = 4;
    long long n3 = 50;

    cout << "Input: " << n1 << ", Output: " << solution.countGoodNumbers(n1) << endl;
    cout << "Input: " << n2 << ", Output: " << solution.countGoodNumbers(n2) << endl;
    cout << "Input: " << n3 << ", Output: " << solution.countGoodNumbers(n3) << endl;
    
    // Custom test
    long long n4;
    cout << "Enter a value for n: ";
    cin >> n4;
    cout << "Input: " << n4 << ", Output: " << solution.countGoodNumbers(n4) << endl;

    return 0;
}

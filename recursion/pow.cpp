#include <iostream>
#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0; // Base case: x^0 = 1

        // Handle negative exponents by taking the reciprocal
        long long power = n; // Use long long to avoid overflow for n = INT_MIN
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;
        double current_product = x;

        while (power > 0) {
            if (power % 2 == 1) { // If the current power is odd
                result *= current_product;
            }
            current_product *= current_product; // Square the base
            power /= 2; // Divide the power by 2
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    double x1 = 2.00000;
    int n1 = 10;
    std::cout << "Input: x = " << x1 << ", n = " << n1 << "\nOutput: " << solution.myPow(x1, n1) << "\n\n";

    // Test case 2
    double x2 = 2.10000;
    int n2 = 3;
    std::cout << "Input: x = " << x2 << ", n = " << n2 << "\nOutput: " << solution.myPow(x2, n2) << "\n\n";

    // Test case 3
    double x3 = 2.00000;
    int n3 = -2;
    std::cout << "Input: x = " << x3 << ", n = " << n3 << "\nOutput: " << solution.myPow(x3, n3) << "\n\n";

    return 0;
}

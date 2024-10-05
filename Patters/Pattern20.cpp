#include<iostream>
using namespace std;

void symmetry(int n) {
    int totalCols = 2 * n;  // Corrected number of columns for the middle stars.

    // Upper part of the pattern
    for (int i = 1; i <= n; i++) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        // Print spaces
        for (int j = 1; j <= totalCols - 2 * i; j++) {
            std::cout << "  ";
        }
        // Print stars again
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    // Lower part of the pattern
    for (int i = n - 1; i >= 1; i--) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        // Print spaces
        for (int j = 1; j <= totalCols - 2 * i; j++) {
            std::cout << "  ";
        }
        // Print stars again
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}



int main(){
    symmetry(3);
    return 0;
}
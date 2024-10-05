#include<iostream>
using namespace std;

void getStarPattern(int n) {
    // Print the first row of n stars
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;

    // Print the middle rows with stars at the start and end, and spaces in between
    for (int i = 0; i < n - 2; i++) {
        std::cout << "*";
        for (int j = 0; j < n - 2; j++) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }

    // Print the last row of n stars, if n is greater than 1
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}


int main(){
    getStarPattern(5);
    return 0;
}
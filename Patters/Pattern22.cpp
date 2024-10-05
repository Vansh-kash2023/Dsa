#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void getNumberPattern(int n) {
    int size = 2 * n - 1; // Calculate the size of the matrix

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            // Calculate the value to print at position (i, j)
            int minDistance = std::min({i, j, size - i + 1, size - j + 1});
            std::cout << n - minDistance + 1;
        }
        std::cout << std::endl;
    }
}


int main(){
    getNumberPattern(4);
    return 0;
}
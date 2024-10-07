#include <bits/stdc++.h>
using namespace std;
int reverseInteger(int n){
    // Write your code here.
    int revnum=0;
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;
    while (n != 0) {
        int lastdigit = n % 10;
        // Check for overflow before adding lastdigit to revnum
        if (revnum > MAX_INT / 10 || (revnum == MAX_INT / 10 && lastdigit > MAX_INT % 10)) {
            return -1; // Overflow occurred
        }
        if (revnum < MIN_INT / 10 || (revnum == MIN_INT / 10 && lastdigit < MIN_INT % 10)) {
            return -1; // Underflow occurred
        }

        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }
    return revnum;
}

int main(){
    cout<< reverseInteger(7657398);
    return 0;
}
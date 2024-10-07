#include <iostream>
using namespace std;

bool isArmstrong(int num) {
    int dup = num;
    // number of digits
    int no_digits = 0;
    while (dup > 0) {
        no_digits += 1;
        dup = dup / 10;
    }

    int result = 0;
    int num1 = num;
    while (num1 > 0) {
        int digit = num1 % 10;
        int power = 1;
        for (int i = 0; i < no_digits; i++) {
            power *= digit;
        }
        
        result += power;
        num1 /= 10;
    }

    return num == result;
}

int main() {
    cout << isArmstrong(121) << endl; // Should print 0 (false)
    cout << isArmstrong(153) << endl; // Should print 1 (true)
    return 0;
}

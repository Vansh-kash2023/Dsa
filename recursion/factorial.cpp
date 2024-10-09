#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void multiply(vector<int> &arr, int &size, int multiplier)

{

    int carry = 0;

    int i = 0;

    for (; i < size; i++)

    {

        int num = arr[i] * multiplier + carry;

        carry = num / 10;

        arr[i] = num % 10;
    }

    while (carry > 0)

    {

        arr[i] = carry % 10;

        carry /= 10;

        i++;

        size++;
    }
}

void factorial(int n)

{

    vector<int> arr(1000, 0);

    arr[0] = 1;

    int size = 1;

    for (int i = 2; i <= n; i++)

    {

        multiply(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--)

    {

        cout << arr[i];
    }
}

int main()
{
    factorial(15);
    return 0;
}
#include <iostream>
using namespace std;

void printNos(int N)
{
    // code here
    int dup = N;
    if (dup != 0)
    {
        cout << dup << " ";
        dup--;
        printNos(dup);
    }
}

int main()
{
    printNos(5);
    return 0;
}
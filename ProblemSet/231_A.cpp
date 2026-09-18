#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int problems = 0;
    while (n--)
    {
        int int_1, int_2, int_3;
        cin >> int_1 >> int_2 >> int_3;
        if (int_1 * int_2 * int_3 == 1 || int_1 * int_2 == 1 || int_2 * int_3 == 1 || int_1 * int_3 == 1)
            problems++;
    }
    cout << problems << endl;
    return 0;
}
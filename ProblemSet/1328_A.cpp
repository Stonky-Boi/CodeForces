#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int quotient = a / b;
        int moves;
        if (a % b == 0)
            moves = 0;
        else
        {
            moves = b * (quotient + 1);
            moves = moves - a;
        }
        cout << moves << endl;
    }
    return 0;
}
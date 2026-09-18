#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int moves = abs(a - b) / (2 * c);
        if (abs(a - b) % (2 * c) != 0)
            moves++;
        cout << moves << endl;
    }
    return 0;
}
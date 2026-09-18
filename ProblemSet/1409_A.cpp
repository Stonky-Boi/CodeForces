#include <iostream>
using namespace std;

int main()
{
    long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        int difference = abs(b - a);
        int moves = difference / 10;
        difference %= 10;
        if (difference > 0)
            moves++;
        cout << moves << endl;
    }
    return 0;
}
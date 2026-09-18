#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        int presses = 0;
        for (int i = 1; i < x[0] - '0'; i++)
            presses += 10;
        presses += (x.size() * (x.size() + 1)) / 2;
        cout << presses << endl;
    }
    return 0;
}
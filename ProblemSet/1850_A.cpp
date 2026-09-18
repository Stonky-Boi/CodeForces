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
        int first = max(a, max(b, c));
        int second = a + b + c - max(a, max(b, c)) - min(a, min(b, c));
        if (first + second >= 10)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
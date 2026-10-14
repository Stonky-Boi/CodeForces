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
        cout << (((c + 1) / 2 + a > c / 2 + b) ? "First" : "Second") << endl;
    }
    return 0;
}
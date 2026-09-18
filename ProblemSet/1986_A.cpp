#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        int f = max(x1, max(x2, x3)) - min(x1, min(x2, x3));
        cout << f << endl;
    }
    return 0;
}
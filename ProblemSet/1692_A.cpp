#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int participants = 0;
        if (b > a)
            participants++;
        if (c > a)
            participants++;
        if (d > a)
            participants++;
        cout << participants << endl;
    }
    return 0;
}
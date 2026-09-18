#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int x1, y1, x2, y2, x3, y3, unsafe = 0;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        if ((y1 == y2) && (y3 < y1))
            unsafe += abs(x1 - x2);
        if ((y2 == y3) && (y1 < y2))
            unsafe += abs(x2 - x3);
        if ((y1 == y3) && (y2 < y1))
            unsafe += abs(x1 - x3);
        cout << unsafe << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x[4], y[4];
        for (int i = 0; i < 4; i++)
            cin >> x[i] >> y[i];
        sort(x, x + 4);
        sort(y, y + 4);
        int area = (x[2] - x[1]) * (y[2] - y[1]);
        cout << area << endl;
    }
    return 0;
}
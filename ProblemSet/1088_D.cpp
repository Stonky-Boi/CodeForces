#include <iostream>
using namespace std;

int ask(int c, int d)
{
    cout << "? " << c << " " << d << endl;
    int response;
    cin >> response;
    return response;
}

int main()
{
    bool greater = ask(0, 0) == 1;
    int a = 0;
    int b = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int q1 = ask(a | (1 << bit), b);
        int q2 = ask(a, b | (1 << bit));
        if (q1 != q2)
        {
            if (q1 == -1)
            {
                a |= 1 << bit;
                b |= 1 << bit;
            }
        }
        else
        {
            if (greater)
                a |= 1 << bit;
            else
                b |= 1 << bit;
            greater = (q1 == 1);
        }
    }
    cout << "! " << a << " " << b << endl;
    return 0;
}
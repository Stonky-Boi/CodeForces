#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int w, h, n;
        cin >> w >> h >> n;
        int sheets = 1;
        while (w % 2 == 0)
        {
            w /= 2;
            sheets *= 2;
        }
        while (h % 2 == 0)
        {
            h /= 2;
            sheets *= 2;
        }
        if (sheets >= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int equal_share = (a + b + c + n) / 3;
        if (((a + b + c + n) % 3 == 0) && (a <= equal_share) && (b <= equal_share) && (c <= equal_share))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int bits = 0;
        for (int i = 0; i < 63; i++)
        {
            if (n & (1ll << i))
                bits++;
        }
        cout << 2 * n - bits << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        long long sum = 0, exor = 0;
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            sum += a;
            exor ^= a;
        }
        cout << 2 << endl;
        cout << exor << " " << (sum + exor) << endl;
    }
    return 0;
}
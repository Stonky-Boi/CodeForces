#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
        cout << m << endl;
        for (int i = 0; i < m; i++)
            cout << 3 * i + 2 << " " << 3 * (n - i) << endl;
    }
    return 0;
}
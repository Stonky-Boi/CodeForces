#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k;
        cin >> n >> k;
        for (int i = 0; i < k - 3; i++)
            cout << "1 ";
        n -= k - 3;
        if (n % 4 == 0)
            cout << n / 4 << " " << n / 4 << " " << n / 2 << endl;
        else if (n % 2 == 0)
            cout << "2 " << n / 2 - 1 << " " << n / 2 - 1 << endl;
        else
            cout << "1 " << (n - 1) / 2 << " " << (n - 1) / 2 << endl;
    }
    return 0;
}
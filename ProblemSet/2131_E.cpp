#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool possible = true;
        if (a[n - 1] != b[n - 1])
            possible = false;
        for (int i = n - 2; i >= 0; i--)
            if ((a[i] != b[i]) && ((a[i] ^ a[i + 1]) != b[i]) && ((a[i] ^ b[i + 1]) != b[i]))
                possible = false;
        cout << ((possible) ? "YES" : "NO") << endl;
    }
    return 0;
}
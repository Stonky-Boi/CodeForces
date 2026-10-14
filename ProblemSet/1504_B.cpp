#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        a.push_back('0');
        b.push_back('0');
        int balance = 0;
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            balance += (a[i] == '1' ? 1 : -1);
            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && balance != 0)
            {
                cout << "NO" << endl;
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "YES" << endl;
    }
    return 0;
}
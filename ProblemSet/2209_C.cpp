#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int response;
        bool found = false;
        for (int i = 1; i <= 2 * n - 2; i += 2)
        {
            cout << "? " << i << " " << i + 1 << endl;
            cin >> response;
            if (response == -1)
                return 0;
            if (response == 1)
            {
                cout << "! " << i << endl;
                found = true;
                break;
            }
        }
        if (found)
            continue;
        int u = 2 * n - 1;
        int v = 2 * n;
        int a = 1;
        int b = 2;
        cout << "? " << u << " " << a << endl;
        cin >> response;
        if (response == -1)
            return 0;
        if (response == 1)
        {
            cout << "! " << u << endl;
            continue;
        }
        cout << "? " << u << " " << b << endl;
        cin >> response;
        if (response == -1)
            return 0;
        if (response == 1)
            cout << "! " << u << endl;
        else
            cout << "! " << v << endl;
    }
    return 0;
}
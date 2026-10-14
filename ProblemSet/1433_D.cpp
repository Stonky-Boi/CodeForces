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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int other = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[0])
            {
                other = i;
                break;
            }
        }
        if (other == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[0])
                cout << other + 1 << " " << i + 1 << endl;
            else
                cout << 1 << " " << i + 1 << endl;
        }
    }
    return 0;
}
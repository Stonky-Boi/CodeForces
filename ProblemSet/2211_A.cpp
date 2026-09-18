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
        vector<int> p(n);
        for (auto &i : p)
            cin >> i;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << 2;
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
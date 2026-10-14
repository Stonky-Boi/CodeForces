#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] += i + 1;
        }
        sort(a.begin(), a.end());
        int teleporters = 0;
        for (const int &i : a)
        {
            c -= i;
            if (c < 0)
                break;
            teleporters++;
        }
        cout << teleporters << endl;
    }
    return 0;
}
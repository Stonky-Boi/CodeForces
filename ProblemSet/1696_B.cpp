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
        int zeroes = 0;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                zeroes++;
            else
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        cout << (zeroes == n ? 0 : (zeroes + r - l + 1 == n ? 1 : 2)) << endl;
    }
    return 0;
}
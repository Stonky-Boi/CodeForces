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
        int n;
        cin >> n;
        vector<int> b(n);
        for (int &i : b)
            cin >> i;
        bool distinct = true;
        sort(b.begin(), b.end());
        for (int i = 1; i < n; i++)
        {
            if (b[i - 1] == b[i])
                distinct = false;
        }
        cout << (distinct ? "NO" : "YES") << endl;
    }
    return 0;
}
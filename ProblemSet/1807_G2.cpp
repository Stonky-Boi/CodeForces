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
        vector<int> c(n);
        for (int &i : c)
            cin >> i;
        sort(c.begin(), c.end());
        bool possible = (c[0] == 1);
        long long sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (c[i] > sum)
            {
                possible = false;
                break;
            }
            sum += c[i];
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
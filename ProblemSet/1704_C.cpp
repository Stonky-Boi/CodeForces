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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<int> gaps;
        for (int i = 1; i < m; i++)
            gaps.push_back(a[i] - a[i - 1] - 1);
        gaps.push_back(n - a[m - 1] + a[0] - 1);
        sort(gaps.begin(), gaps.end(), greater<int>());
        int days = 0;
        int saved = 0;
        for (int &i : gaps)
        {
            i -= 2 * days;
            if (i <= 0)
                continue;
            if (i == 1)
            {
                saved++;
                days++;
            }
            else
            {
                saved += i - 1;
                days += 2;
            }
        }
        cout << n - saved << endl;
    }
    return 0;
}
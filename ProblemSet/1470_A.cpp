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
        vector<int> k(n), c(m);
        for (int &i : k)
            cin >> i;
        for (int &i : c)
            cin >> i;
        sort(k.begin(), k.end(), greater<int>());
        long long cost = 0;
        int j = 0;
        for (const int &i : k)
        {
            if (j < i && c[j] < c[i - 1])
            {
                cost += c[j];
                j++;
            }
            else
                cost += c[i - 1];
        }
        cout << cost << endl;
    }
    return 0;
}
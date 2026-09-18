#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), evens, odds;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                evens.push_back(a[i]);
            else
                odds.push_back(a[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        int even_index = 0, odd_index = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                a[i] = evens[even_index++];
            else
                a[i] = odds[odd_index++];
        }
        bool is_sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
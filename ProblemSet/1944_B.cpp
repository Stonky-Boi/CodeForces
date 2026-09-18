#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long int> a(2 * n);
        vector<long int> frequency(n + 1, 0);
        for (long int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            if (i < n)
                frequency[a[i]]++;
        }
        vector<long int> l, r;
        for (long int i = 1; i <= n; i++)
        {
            if (frequency[i] == 2 && l.size() < 2 * k)
            {
                l.push_back(i);
                l.push_back(i);
            }
            else if (frequency[i] == 0 && r.size() < 2 * k)
            {
                r.push_back(i);
                r.push_back(i);
            }
        }
        while (l.size() < r.size())
            r.pop_back();
        while (r.size() < l.size())
            l.pop_back();
        for (long int i = 1; l.size() < 2 * k && i <= n; i++)
        {
            if (frequency[i] % 2)
            {
                l.push_back(i);
                r.push_back(i);
            }
        }
        for (long int i = 0; i < l.size(); i++)
            cout << l[i] << " ";
        cout << endl;
        for (long int i = 0; i < r.size(); i++)
            cout << r[i] << " ";
        cout << endl;
    }
    return 0;
}
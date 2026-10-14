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
        vector<int> a(n, 0);
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        string s;
        cin >> s;
        vector<int> balance(n);
        for (int i = 0; i < n; i++)
            balance[i] = (s[i] == 'W' ? 1 : -1);
        int subtrees = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (balance[i] == 0)
                subtrees++;
            if (i > 0)
                balance[a[i]] += balance[i];
        }
        cout << subtrees << endl;
    }
    return 0;
}
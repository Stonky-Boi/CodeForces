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
        vector<int> a(n), b(m);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        sort(b.begin(), b.end(), greater<int>());
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] > b[j])
                cout << a[i++] << " ";
            else
                cout << b[j++] << " ";
        }
        while (i < n)
            cout << a[i++] << " ";
        while (j < m)
            cout << b[j++] << " ";
        cout << endl;
    }
    return 0;
}
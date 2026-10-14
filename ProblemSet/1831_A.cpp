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
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        int maximum = *max_element(a.begin(), a.end()) + 1;
        for (int i = 0; i < n; i++)
            b[i] = maximum - a[i];
        for (const int &i : b)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
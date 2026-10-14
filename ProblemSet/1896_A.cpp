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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        cout << (a[0] == sorted[0] ? "YES" : "NO") << endl;
    }
    return 0;
}
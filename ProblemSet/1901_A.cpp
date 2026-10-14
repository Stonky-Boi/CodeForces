#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int capacity = 0;
        int prev = 0;
        for (const int &i : a)
        {
            capacity = max(capacity, i - prev);
            prev = i;
        }
        capacity = max(capacity, 2 * (x - a[n - 1]));
        cout << capacity << endl;
    }
    return 0;
}
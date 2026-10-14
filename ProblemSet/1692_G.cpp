#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int window = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= k && a[i - k] < 2ll * a[i - k + 1])
                window--;
            if (i + 1 < n && a[i] < 2ll * a[i + 1])
                window++;
            if (window == k)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
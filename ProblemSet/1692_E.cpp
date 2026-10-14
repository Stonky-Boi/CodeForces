#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int i = 0;
        int sum = 0, length = -1;
        for (int j = 0; j < n; j++)
        {
            sum += a[j];
            while (sum > s)
            {
                sum -= a[i];
                i++;
            }
            if (sum == s)
                length = max(length, j - i + 1);
        }
        cout << (length == -1 ? -1 : n - length) << endl;
    }
    return 0;
}
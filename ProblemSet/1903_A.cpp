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
        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                sorted = false;
                break;
            }
        }
        cout << ((!sorted && k == 1) ? "NO" : "YES") << endl;
    }
    return 0;
}
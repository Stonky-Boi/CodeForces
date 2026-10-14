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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        bool sorted = true;
        int difference = 1e9;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                sorted = false;
                break;
            }
            difference = min(difference, a[i] - a[i - 1]);
        }
        cout << (sorted ? (difference / 2 + 1) : 0) << endl;
    }
    return 0;
}
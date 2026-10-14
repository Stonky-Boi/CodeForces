#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        int x = numeric_limits<int>::max();
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] != i)
                x &= p[i];
        }
        cout << x << endl;
    }
    return 0;
}
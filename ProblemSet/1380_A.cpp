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
        vector<int> p(n);
        for (int &i : p)
            cin >> i;
        bool possible = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (p[i - 1] < p[i] && p[i] > p[i + 1])
            {
                cout << "YES" << endl;
                cout << i << " " << i + 1 << " " << i + 2 << endl;
                possible = true;
                break;
            }
        }
        if (!possible)
            cout << "NO" << endl;
    }
    return 0;
}
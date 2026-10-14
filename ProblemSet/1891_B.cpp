#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), x(q);
        for (int &i : a)
            cin >> i;
        int minimum = 31;
        for (int &i : x)
        {
            cin >> i;
            if (i >= minimum)
                continue;
            for (int &j : a)
            {
                if (j % (1 << i) == 0)
                    j += (1 << (i - 1));
            }
            minimum = i;
        }
        for (const int &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
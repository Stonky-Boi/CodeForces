#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> integers;
        if (x != 1)
            integers.assign(n, 1);
        else if (n % 2 == 0 && k >= 2)
            integers.assign(n / 2, 2);
        else if (n % 2 == 1 && k >= 3)
        {
            integers.assign((n - 3) / 2, 2);
            integers.push_back(3);
        }
        if (integers.empty())
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << integers.size() << endl;
            for (const int &i : integers)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
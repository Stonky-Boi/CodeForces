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
        int value = 0;
        for (int b = 30; b >= 0; b--)
        {
            int cost = 0;
            for (const int &i : a)
            {
                if ((i & (1 << b)) == 0)
                    cost++;
            }
            if (k >= cost)
            {
                k -= cost;
                value |= (1 << b);
            }
        }
        cout << value << endl;
    }
    return 0;
}
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
        vector<int> count(31, 0);
        for (int &i : a)
        {
            cin >> i;
            int bit = 0;
            while (i > 1)
            {
                i >>= 1;
                bit++;
            }
            count[bit]++;
        }
        long long pairs = 0;
        for (const int &i : count)
            pairs += 1ll * i * (i - 1) / 2;
        cout << pairs << endl;
    }
}
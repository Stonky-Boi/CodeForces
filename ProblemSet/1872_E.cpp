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
        string s;
        cin >> s;
        vector<int> prefix_xor(n + 1, 0);
        int xor0 = 0, xor1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                xor0 ^= a[i];
            else
                xor1 ^= a[i];
            prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                int segment = prefix_xor[r] ^ prefix_xor[l - 1];
                xor0 ^= segment;
                xor1 ^= segment;
            }
            else
            {
                int g;
                cin >> g;
                cout << (g == 0 ? xor0 : xor1) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
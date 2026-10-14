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
        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] ^ a[i];
        long long tuples = 0;
        for (int k = 0; k < 30; k++)
        {
            int left[2] = {0, 0};
            int right[2] = {0, 0};
            left[(p[0] >> k) & 1]++;
            for (int i = 1; i <= n; i++)
                right[(p[i] >> k) & 1]++;
            for (int i = 0; i < n; i++)
            {
                int bit = 31 - __builtin_clz(a[i]);
                if (bit == k)
                {
                    int b1 = (p[i] >> k) & 1;
                    int b2 = (p[i + 1] >> k) & 1;
                    int l0 = left[b1];
                    int l1 = left[1 - b1];
                    int r0 = right[b2];
                    int r1 = right[1 - b2];
                    tuples += 1ll * l0 * r1 + 1ll * l1 * r0;
                }
                int b = (p[i + 1] >> k) & 1;
                right[b]--;
                left[b]++;
            }
        }
        cout << tuples << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(30, 0);
        for (int &i : a)
        {
            cin >> i;
            for (int b = 0; b < 30; b++)
                if (((i >> b) & 1) == 1)
                    freq[b]++;
        }
        int g = 0;
        for (const int &f : freq)
            g = gcd(g, f);
        for (int k = 1; k <= n; k++)
        {
            if (g % k == 0)
                cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
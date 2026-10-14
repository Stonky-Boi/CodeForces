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
        for (int &i : a)
            cin >> i;
        int points = 0;
        for (int k = 1; k <= n; k++)
        {
            if (n % k != 0)
                continue;
            int g = 0;
            for (int i = 0; i + k < n; i++)
                g = gcd(g, abs(a[i] - a[i + k]));
            if (g != 1)
                points++;
        }
        cout << points << endl;
    }
    return 0;
}
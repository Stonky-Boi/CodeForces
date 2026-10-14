#include <iostream>
#include <vector>
#include <map>
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    map<pair<int, int>, int> d;
    int always = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (b[i] == 0)
                always++;
            continue;
        }
        int p = -b[i], q = a[i];
        if (q < 0)
        {
            p *= -1;
            q *= -1;
        }
        int g = gcd(abs(p), q);
        p /= g;
        q /= g;
        d[{p, q}]++;
    }
    int maximum = always;
    for (const auto &[_, f] : d)
        maximum = max(maximum, always + f);
    cout << maximum << endl;
    return 0;
}
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
        vector<int> p(n);
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i - 1];
            k = gcd(k, abs(p[i - 1] - i));
        }
        cout << k << endl;
    }
    return 0;
}
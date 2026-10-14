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
        int x = 0;
        for (int i = 0; i <= n / 2; i++)
            x = gcd(x, abs(a[i] - a[n - i - 1]));
        cout << x << endl;
    }
    return 0;
}
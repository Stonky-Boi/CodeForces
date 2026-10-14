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
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int &i : a)
    {
        cin >> i;
        if (i == 1)
            ones++;
    }
    if (ones > 0)
    {
        cout << n - ones << endl;
        return 0;
    }
    int min_length = n + 1;
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = i; j < n; j++)
        {
            g = gcd(g, a[j]);
            if (g == 1)
            {
                min_length = min(min_length, j - i + 1);
                break;
            }
        }
    }
    cout << (min_length == n + 1 ? -1 : n + min_length - 2) << endl;
    return 0;
}
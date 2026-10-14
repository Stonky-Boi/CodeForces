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
        bool possible = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (gcd(a[i], a[j]) <= 2)
                {
                    possible = true;
                    break;
                }
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}
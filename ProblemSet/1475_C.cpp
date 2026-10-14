#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> A(k), B(k);
        vector<int> boys(a + 1), girls(b + 1);
        for (int &i : A)
            cin >> i;
        for (int &i : B)
            cin >> i;
        for (int i = 0; i < k; i++)
        {
            boys[A[i]]++;
            girls[B[i]]++;
        }
        long long ways = 1ll * k * (k - 1) / 2;
        for (int i = 1; i <= a; i++)
            ways -= 1ll * boys[i] * (boys[i] - 1) / 2;
        for (int i = 1; i <= b; i++)
            ways -= 1ll * girls[i] * (girls[i] - 1) / 2;
        cout << ways << endl;
    }
    return 0;
}
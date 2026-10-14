#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int MAXA = 2e5;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> spf(MAXA + 1); // smallest prime factor
    for (int i = 0; i <= MAXA; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= MAXA; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    vector<int> count(MAXA + 1, 0);
    vector<int> min1(MAXA + 1, 1e9);
    vector<int> min2(MAXA + 1, 1e9);
    for (int i : a)
    {
        while (i > 1)
        {
            int p = spf[i];
            int power = 0;
            while (i % p == 0)
            {
                i /= p;
                power++;
            }
            count[p]++;
            if (power < min1[p])
            {
                min2[p] = min1[p];
                min1[p] = power;
            }
            else if (power < min2[p])
                min2[p] = power;
        }
    }
    long long g = 1;
    for (int i = 2; i <= MAXA; i++)
    {
        int exponent = 0;
        if (count[i] == n)
            exponent = min2[i];
        else if (count[i] == n - 1)
            exponent = min1[i];
        while (exponent--)
            g *= i;
    }
    cout << g << endl;
    return 0;
}
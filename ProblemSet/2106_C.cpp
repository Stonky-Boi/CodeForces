#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k, missing = 0, ways;
        cin >> n >> k;
        long int a[n], b[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        long int a_max = a[0], a_min = a[0], first_positive;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a_max)
                a_max = a[i];
            if (a[i] < a_min)
                a_min = a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] == -1)
                missing++;
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != -1)
            {
                first_positive = i;
                break;
            }
        }
        if (missing == n)
        {
            ways = k - a_max + a_min + 1;
            ways = (ways < 0) ? 0 : ways;
        }
        else
        {
            bool complementary = true;
            int sum = a[first_positive] + b[first_positive];
            for (int i = 0; i < n; i++)
            {
                if (b[i] != -1 && a[i] + b[i] != sum)
                    complementary = false;
            }
            for (int i = 0; i < n; i++)
            {
                if (b[i] == -1)
                {
                    long int inferred_b = sum - a[i];
                    if (inferred_b < 0 || inferred_b > k)
                    {
                        complementary = false;
                        break;
                    }
                }
            }
            ways = complementary ? 1 : 0;
        }
        cout << ways << endl;
    }
    return 0;
}
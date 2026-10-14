#include <iostream>
#include <vector>
using namespace std;

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
        long long difference = 0;
        for (int k = 1; k <= n; k++)
        {
            if (n % k == 0)
            {
                long long maximum = -1e18, minimum = 1e18;
                for (int i = 0; i < n; i += k)
                {
                    long long sum = 0;
                    for (int j = i; j < i + k; ++j)
                        sum += a[j];
                    maximum = max(maximum, sum);
                    minimum = min(minimum, sum);
                }
                difference = max(difference, maximum - minimum);
            }
        }
        cout << difference << endl;
    }
    return 0;
}
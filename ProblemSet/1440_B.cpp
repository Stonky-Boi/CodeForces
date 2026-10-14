#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n * k);
        for (int &i : a)
            cin >> i;
        int i = n * k;
        long long sum = 0;
        while (k--)
        {
            i -= (n / 2 + 1);
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
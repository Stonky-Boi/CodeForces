#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int experience = 0, sum = 0, max_b = 0;
        for (int i = 0; i < min(n, k); i++)
        {
            sum += a[i];
            max_b = max(max_b, b[i]);
            int total_xp = sum + max_b * (k - i - 1);
            experience = max(experience, total_xp);
        }
        cout << experience << endl;
    }
    return 0;
}
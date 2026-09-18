#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int min_moves = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int candy = *min_element(a, a + n), orange = *min_element(b, b + n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] > candy && b[i] > orange)
            {
                int moves = min(a[i] - candy, b[i] - orange);
                min_moves += moves;
                a[i] -= moves;
                b[i] -= moves;
            }
            if (a[i] > candy)
                min_moves += a[i] - candy;
            if (b[i] > orange)
                min_moves += b[i] - orange;
        }
        cout << min_moves << endl;
    }
    return 0;
}
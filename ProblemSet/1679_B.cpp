#include <iostream>
using namespace std;

int main()
{
    int n, q, t, i;
    cin >> n >> q;
    long long int a[n], x, sum = 0, global_value = -1;
    bool updated[n] = {false};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> i >> x;
            i--;
            if (updated[i])
                sum += x - a[i];
            else
            {
                if (global_value == -1)
                    sum += x - a[i];
                else
                    sum += x - global_value;
            }
            a[i] = x;
            updated[i] = true;
        }
        else
        {
            cin >> x;
            global_value = x;
            sum = x * n;
            fill(updated, updated + n, false);
        }
        cout << sum << endl;
    }
    return 0;
}
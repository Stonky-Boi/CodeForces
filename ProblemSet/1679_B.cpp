#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    long long sum = 0;
    for (int &i : a)
    {
        cin >> i;
        sum += i;
    }
    vector<int> version(n, 0);
    int global_value = 0;
    int curr_version = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;
            if (version[i] != curr_version)
            {
                a[i] = global_value;
                version[i] = curr_version;
            }
            sum -= a[i];
            sum += x;
            a[i] = x;
        }
        else
        {
            int x;
            cin >> x;
            global_value = x;
            curr_version++;
            sum = 1ll * x * n;
        }
        cout << sum << endl;
    }
    return 0;
}
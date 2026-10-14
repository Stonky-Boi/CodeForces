#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0, min_time = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        min_time = max(min_time, (sum + i) / (i + 1));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        cout << (t < min_time ? -1 : (sum + t - 1) / t) << endl;
    }
    return 0;
}
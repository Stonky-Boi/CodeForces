#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long m;
        cin >> n >> m;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int opponents_beaten = 0;
        long long time_left = m;
        for (int i = 0; i < n && b[i] <= time_left; i++)
        {
            time_left -= b[i];
            opponents_beaten++;
        }
        if (opponents_beaten != 0 && opponents_beaten != n && time_left + b[opponents_beaten - 1] >= a[opponents_beaten])
            opponents_beaten++;
        cout << n + 1 - opponents_beaten << endl;
    }
    return 0;
}
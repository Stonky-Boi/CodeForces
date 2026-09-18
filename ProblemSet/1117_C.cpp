#include <iostream>
using namespace std;

int main()
{
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long position_x[n + 1], position_y[n + 1];
    position_x[0] = position_y[0] = 0;
    for (int i = 0; i < n; i++)
    {
        position_x[i + 1] = position_x[i];
        position_y[i + 1] = position_y[i];
        if (s[i] == 'U')
            position_y[i + 1]++;
        else if (s[i] == 'D')
            position_y[i + 1]--;
        else if (s[i] == 'L')
            position_x[i + 1]--;
        else if (s[i] == 'R')
            position_x[i + 1]++;
    }
    long long total_x = position_x[n], total_y = position_y[n];
    long long l = 0, r = 1e18, days = -1;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        long long cycles = m / n;
        int extra = m % n;
        long long wx = cycles * total_x + position_x[extra];
        long long wy = cycles * total_y + position_y[extra];
        long long dist = abs(x2 - (x1 + wx)) + abs(y2 - (y1 + wy));
        if (dist <= m)
        {
            days = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << days << endl;
    return 0;
}
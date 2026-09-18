#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool can(int n, double d, vector<long long> &x)
{
    int count = 0;
    int i = 0;
    while (i < n)
    {
        count++;
        double limit = x[i] + 2.0 * d;
        while (i < n && x[i] <= limit)
            i++;
        if (count > 3)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> x(n);
    for (long long &i : x)
        cin >> i;
    sort(x.begin(), x.end());
    double low = 0, high = 1e9;
    for (int i = 0; i < 60; i++)
    {
        double mid = (low + high) / 2.0;
        if (can(n, mid, x))
            high = mid;
        else
            low = mid;
    }
    double d = high;
    vector<double> stations;
    int i = 0;
    while (i < n)
    {
        int start = i;
        double limit = x[i] + 2.0 * d;
        while (i < n && x[i] <= limit)
            i++;
        int end = i - 1;
        double center = (x[start] + x[end]) / 2.0;
        stations.push_back(center);
    }
    while (stations.size() < 3)
        stations.push_back(stations.back());
    cout << fixed << setprecision(6) << d << endl;
    for (double s : stations)
        cout << s << " ";
    cout << endl;
    return 0;
}
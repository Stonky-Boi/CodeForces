#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maximum_value = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maximum_value = max(maximum_value, a[i]);
        }
        vector<long long int> segment_count(maximum_value + 1, 0);
        for (int i = 0; i < n; i++)
            segment_count[a[i]]++;
        long long int ways = 0;
        long long int available_segments = 0;
        for (int i = 0; i < segment_count.size(); i++)
        {
            if (segment_count[i] >= 3)
                ways += segment_count[i] * (segment_count[i] - 1) * (segment_count[i] - 2) / 6;
            if (segment_count[i] >= 2)
                ways += segment_count[i] * (segment_count[i] - 1) / 2 * available_segments;
            available_segments += segment_count[i];
        }
        cout << ways << endl;
    }
    return 0;
}
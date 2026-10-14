#include <iostream>
#include <vector>
using namespace std;

int area()
{
    int k;
    cin >> k;
    vector<int> points(k);
    for (int &i : points)
        cin >> i;
    return points[k - 1] - points[0];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h;
        cin >> w >> h;
        long long max_area = 0;
        max_area = max(max_area, 1ll * area() * h);
        max_area = max(max_area, 1ll * area() * h);
        max_area = max(max_area, 1ll * area() * w);
        max_area = max(max_area, 1ll * area() * w);
        cout << max_area << endl;
    }
    return 0;
}
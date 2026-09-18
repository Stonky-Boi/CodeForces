#include <iostream>
using namespace std;

long long int intersection_area(long int x1, long int y1, long int x2, long int y2, long int x3, long int y3, long int x4, long int y4)
{
    long long int x_overlap = max(0L, min(x2, x4) - max(x1, x3));
    long long int y_overlap = max(0L, min(y2, y4) - max(y1, y3));
    return x_overlap * y_overlap;
}

int main()
{
    long int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    long long int white_area = 1LL * (x2 - x1) * (y2 - y1);
    long long int intersection1 = intersection_area(x1, y1, x2, y2, x3, y3, x4, y4);
    long long int intersection2 = intersection_area(x1, y1, x2, y2, x5, y5, x6, y6);
    long int lx = max(x1, max(x3, x5));
    long int ly = max(y1, max(y3, y5));
    long int rx = min(x2, min(x4, x6));
    long int ry = min(y2, min(y4, y6));
    long long int intersection = intersection_area(lx, ly, rx, ry, lx, ly, rx, ry);
    long long int covered = intersection1 + intersection2 - intersection;
    if (white_area > covered)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}